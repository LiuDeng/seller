//
//  Login_Post.m
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import "Login_Post.h"

#import "JsonUtil.h"

@implementation Login_Post

- (id)initWithAccount:(NSString*)account
             Password:(NSString*)password {
    if (self = [super initWithURL:[BaseRestApi getRestApiURL:@"auth/login"] httpMethod:kHttpPost]) {
        _account = account;
        _password = password;
    }
    return self;
}

- (id)prepareRequestData {
    return @{
             @"account":_account,
             @"password":_password
             };
}

- (BOOL)parseResponseJson:(NSDictionary *)json {
    NSDictionary *dict = [JsonUtil toDictionary:json forKey:@"user_info"];
    
    if (dict) {
        // 未完
//        self.user_info = [user_info objectWithKeyValues:dict];
//        self.user_info.account = self.account;
    }
    
    dict = [JsonUtil toDictionary:json forKey:@"wallet"];
    if (dict) {
//        self.wallet = [wallet_info objectWithKeyValues:dict];
    }
    
//    return self.user_info && self.user_info.token.length && self.wallet;
    return YES;
}

- (NSString *)mockFile {
    return @"auth_login";
}

@end
