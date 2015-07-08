//
//  BaseRestApi.m
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import "BaseRestApi.h"

#import "URLHelper.h"
#import "JsonUtil.h"

@interface BaseRestApi ()

{
    BOOL _requestIsJson;
}

@end

static NSString* s_account = nil;
static NSString* s_token = nil;


@implementation BaseRestApi

+ (NSString *)getRestApiURL:(NSString *)relativeURL {
    return [[URLHelper getInstance] restApiURL:relativeURL];
}

+ (void)setAuthAccount:(NSString *)account token:(NSString *)token {
    s_account = account;
    s_token = token;
}

- (NSData *)requestData {
    id requestData = [self prepareRequestData];
    
    if ([requestData isKindOfClass:NSData.class]) {
        return requestData;
    }
    else if ([requestData isKindOfClass:NSDictionary.class]) {
        NSMutableDictionary* dict = [NSMutableDictionary dictionaryWithDictionary:requestData];
        NSData * jsondata=[NSJSONSerialization dataWithJSONObject:dict options:NSJSONWritingPrettyPrinted error:nil];
        NSLog(@"RestApi Request:%@", [[NSString alloc] initWithData:jsondata encoding:NSUTF8StringEncoding]);
        _requestIsJson = YES;
        return jsondata;
    }
    else if ([requestData isKindOfClass:NSString.class]) {
        if ([requestData length]) {
            NSLog(@"RestApi Request:%@", requestData);
            return [((NSString*)requestData) dataUsingEncoding:NSUTF8StringEncoding];
        }
    }
    return nil;
}

- (void)call:(BOOL)async timeout:(float)timeout {
    
#if APP_STATUS == AppStatus_Develop
    if ([self mockType] != MockType_None) {
        NSLog(@"本地数据");
    }
    else
#endif
    {
        [super call:async timeout:timeout];
    }
}

- (void)setRequestHeader:(NSMutableURLRequest *)request {
    if (_requestIsJson) {
        [request setValue:@"application/json; charset=utf-8" forHTTPHeaderField:@"Content-Type"];
    }
    if (s_token) {
        NSLog(@"s_token = %@",s_token);
        
        [request setValue:s_account forHTTPHeaderField:@"Auth_Account"];
        [request setValue:s_token forHTTPHeaderField:@"Auth_Token"];
    }
    
//    [request setValue:kHarpyCurrentVersion forHTTPHeaderField:@"Client_Version"];
//    [request setValue:CLIENT_TYPE forHTTPHeaderField:@"Client_Type"];
//    [request setValue:[DeviceHelper systemVersion] forHTTPHeaderField:@"System_Version"];
//    [request setValue:[DeviceHelper deviceid] forHTTPHeaderField:@"Device_ID"];
//    [request setValue:[DeviceHelper deviceName] forHTTPHeaderField:@"Device_Name"];
//    [request setValue:[[AFNetworkReachabilityManager sharedManager] localizedNetworkReachabilityStatusString] forHTTPHeaderField:@"Environment_Network"];
}

#pragma mark - Subclassing methods
- (BOOL)responseIsJson {
    return YES;
}

- (id)prepareRequestData {
    return nil;
}

- (BOOL)parseResponseData:(id)responseObject {
    return YES;
}

- (BOOL)parseResponseJson:(NSDictionary *)json {
    return YES;
}

- (void)printResponse:(id)responseObject {
    NSLog(@"RestApi Response: %@", [[NSString alloc] initWithData:responseObject encoding:NSUTF8StringEncoding]);
}


#pragma mark - Override methods

- (void)doSuccess:(id)responseObject {
    [self printResponse:responseObject];
    
    @try {
        if ([self responseIsJson]) {
            
            NSDictionary *json = [JsonUtil toJson:responseObject];
            
            self.message = [JsonUtil toString:json forKey:@"msg"];
            self.code = [JsonUtil toInteger:json forKey:@"ret" defaultValue:RestApi_Error];
            
            // 检查更新 - 未完
            
            //
            if (self.code == RestApi_OK && [self parseResponseJson:json]) {
                [self onSuccessed];
            }
            else if (self.code == RestApi_InvalidToken) {
                [self onInvalidToken];
            }
            else {
                if (self.code == RestApi_OK) {
                    self.code = RestApi_Internal_JSONInvalid;
                }
                [self onFailed];
            }
            
        }
    }
    @catch (NSException *exception) {
        [self onError:nil];
    }
    @finally {
        
    }
}

- (void)onSuccessed {
    [super onSuccessed];
}

- (void)onFailed {
    [super onFailed];
}

- (void)onCancelled {
    [super onCancelled];
}

- (void)onTimeout {
    [super onTimeout];
}

- (void)onError:(NSError *)error {
    [super onError:error];
}

- (void)onInvalidToken {
    [self onFailed];
//    [[Workspace getInstance] onLogOut];
//    [[MineNotify sharedInstance] postLogoutNotify];
}

#pragma mark - Help methods


#pragma mark - Simulate methods

- (MockType)mockType {
    return MockType_None;
}

- (NSString *)mockFile {
    return nil;
}

- (NSData *)mockData {
    return nil;
}

- (void)mockSleep:(float)seconds {
#if APP_STATUS == AppStatus_Develop
    usleep(1000 * 1000 * seconds);
#endif
}

@end
