//
//  LoginHelper.h
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import <Foundation/Foundation.h>

#import "ApiHeader.h"

@interface LoginHelper : NSObject

+ (void)loginWithTel:(NSString *)tel password:(NSString *)psd completion:(void (^)(BOOL success, Login_Post *loginPost))block ;

@end
