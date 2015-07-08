//
//  BaseRestApi.h
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import "RestApi.h"

@class BaseRestApi;

// API 返回值
typedef NS_ENUM(NSInteger, RestApiCode) {
    //成功
    RestApi_OK = 0,
    
    //错误
    RestApi_Error = 1,
    
    //错误码为RestApi_InvalidToken时，跳转到登录界面
    //令牌无效
    RestApi_InvalidToken = 2,
    
    //数据没有变化
    RestApi_NotModify = 16,
    
    //更新
    RestApi_UpdateVersion = 108,
    
    //余额不足
    RestApi_Wallet_NotEnough = 1001,
    
    //JSON数据异常
    RestApi_Internal_JSONInvalid = 0x8002,
};

typedef NS_ENUM(NSInteger, MockType) {
    MockType_None,
    MockType_File,
    MockType_Data,
};

@interface BaseRestApi : RestApi

+ (NSString *)getRestApiURL:(NSString *)relativeURL;

+ (void)setAuthAccount:(NSString *)account token:(NSString *)token;

@property RestApiCode code;
@property (nonatomic, strong) NSString *message;
//@property (nonatomic, strong) update_info *updateInfo;

#pragma mark - Subclassing methods

- (BOOL)responseIsJson;

- (id)prepareRequestData;

- (BOOL)parseResponseData:(id)responseObject;

- (BOOL)parseResponseJson:(NSDictionary *)json;

#pragma mark - Mock
- (MockType)mockType;
- (NSString *)mockFile;
- (NSData *)mockData;
- (void)mockSleep:(float)seconds;


@end
