//
//  Login_Post.h
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import "BaseRestApi.h"

@interface Login_Post : BaseRestApi

- (id)initWithAccount:(NSString*)account
             Password:(NSString*)password;

// 输入值
@property (nonatomic, strong) NSString* account;
@property (nonatomic, strong) NSString* password;

@end
