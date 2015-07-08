//
//  RestApi.m
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import "RestApi.h"

#import "AFNetworking.h"

@interface RestApi ()

{
    NSString *_url;
    HttpMethods _httpMethod;
    AFHTTPRequestOperation *_operation;
    
    BOOL _isCancel;
}

@end

@implementation RestApi

+ (NSString *)method:(HttpMethods)httpMethod {
    switch (httpMethod) {
        case kHttpPost:
            return @"Post";
        case kHttpGet:
            return @"Get";
        case kHttpPut:
            return @"Put";
        case kHttpDelete:
            return @"Delete";
            
        default:
            return @"Unknown";
            break;
    }
}

- (id)initWithURL:(NSString *)url httpMethod:(HttpMethods)httpMethod {
    if (self = [super init]) {
        _url = url;
        _httpMethod = httpMethod;
        _isCancel = NO;
    }
    return self;
}

- (void)dealloc {
    [self cancel];
}

- (void)raiseException:(NSString *)exception {
    [NSException raise:exception format:nil];
}

// 异步调用
- (void)call {
    [self call:YES];
}

- (void)call:(BOOL)async {
    [self call:async timeout:10.0];
}

- (void)call:(BOOL)async timeout:(float)timeout {
    if ([NSThread isMainThread] && !async) {
        //主线程不允许同步调用
        [self raiseException:@"应答数据不能为nil, responseData==nil"];
        return;
    }
    
    NSMutableURLRequest *request = [[NSMutableURLRequest alloc] init];
    
    @try {
        NSMutableString *strUrl = [[NSMutableString alloc] initWithString:_url];
        
        NSDictionary *params = [self queryParameters];
        if (params) {
            NSArray *keys = params.allKeys;
            for (int i=0; i<keys.count; i++) {
                NSString *key = keys[i];
                NSString *value = params[key];
                
                //key = [URLUtil encode:key];
                //value = [URLUtil encode:value];
                
                if (i == 0) {
                    [strUrl appendString:@"?"];
                }
                else {
                    [strUrl appendString:@"&"];
                }
                
                [strUrl appendString:key];
                [strUrl appendString:@"="];
                [strUrl appendString:value];
            }
        }
        
        [request setURL:[NSURL URLWithString:strUrl]];
        [request setHTTPMethod:[self getHttpMethod]];
        [request setTimeoutInterval:timeout];
        
        if (_httpMethod == kHttpPost || _httpMethod == kHttpPut) {
            // body
            NSData *httpBody = [self requestData];
            if (httpBody) {
                [request setValue:[NSString stringWithFormat:@"%lu",(unsigned long)httpBody.length] forHTTPHeaderField:@"Content-Length"];
                [request setHTTPBody:httpBody];
            }
        }
        
        // 头参数
        [self setRequestHeader:request];
    }
    @catch (NSException *exception) {
        NSLog(@"Exception:%@",exception);
    }
    @finally {
        
    }
    
    NSCondition *itlock = nil;
    
    NSLog(@"RestApi URL:%@",_url);
    
    __weak RestApi *_weakSelf = self;
    _operation = [[AFHTTPRequestOperation alloc] initWithRequest:request];
    _operation.responseSerializer = [[AFHTTPResponseSerializer alloc] init];
    
    if (async) {
        // 异步
        [_operation setCompletionBlockWithSuccess:^(AFHTTPRequestOperation *operation, id responseObject) {
            [_weakSelf doSuccess:responseObject];
        } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
            [_weakSelf doFailure:error];
        }];
    }
    else {
        // 同步
        itlock = [[NSCondition alloc] init];
        
        [_operation setCompletionBlockWithSuccess:^(AFHTTPRequestOperation *operation, id responseObject) {
            [_weakSelf doSuccess:responseObject];
            
            [itlock lock];
            [itlock signal];
            [itlock unlock];
        } failure:^(AFHTTPRequestOperation *operation, NSError *error) {
            [_weakSelf doFailure:error];
            
            [itlock lock];
            [itlock signal];
            [itlock unlock];
        }];
    }
    
    [_operation start];
    
    if (itlock) {
        [itlock lock];
        [itlock wait];
        [itlock unlock];
    }
}

- (void)cancel {
    if (!_isCancel) {
        [_operation cancel];
        _isCancel = YES;
    }
}

- (void)setRequestHeader:(NSMutableURLRequest *)request {
    
}

#pragma mark - RestAPI resutls
- (void)doSuccess:(id)responseObject {
    [self onSuccessed];
}
- (void)doFailure:(NSError *)error {
    NSLog(@"DoFailure:%@",error);
    
    if ([error.domain isEqualToString:NSURLErrorDomain] && error.code == NSURLErrorCancelled) {
        [self onCancelled];
    }
    else if ([error.domain isEqualToString:NSURLErrorDomain] && error.code == NSURLErrorTimedOut) {
        // 超时
        [self onTimeout];
    }
    else {
        // 其他错误
        [self onError:error];
    }
}

#pragma mark - Subclassing methods

- (void)onSuccessed {
    _isCompleted = YES;
    _isSuccessed = YES;
}

- (void)onFailed {
    _isCompleted = YES;
}

- (void)onCancelled {
    _isCompleted = YES;
    _isCancelled = YES;
    
}

- (void)onTimeout {
    _isCompleted = YES;
    _isTimeout = YES;
}

- (void)onError:(NSError *)error {
    _isCompleted = YES;
    _error = error;
}

- (NSData *)requestData {
    return nil;
}

- (NSDictionary *)queryParameters {
    return nil;
}

#pragma mark - Help methods

- (NSString*)getHttpMethod {
    switch (_httpMethod) {
        case kHttpGet:
            return @"GET";
        case kHttpPost:
            return @"POST";
        case kHttpPut:
            return @"PUT";
        case kHttpDelete:
            return @"DELETE";
        default:
            return nil;
    }
}

@end
