//
//  LoginHelper.m
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import "LoginHelper.h"

#import "GCDUtil.h"


@implementation LoginHelper

+ (void)loginWithTel:(NSString *)tel password:(NSString *)psd completion:(void (^)(BOOL success, Login_Post *loginPost))block  {
    [GCDUtil runInGlobalQueue:^{
        
        Login_Post *login = [[Login_Post alloc] initWithAccount:tel Password:psd];
        [login call:NO];
        
        
    }];
}

@end
