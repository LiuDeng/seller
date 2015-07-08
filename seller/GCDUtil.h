//
//  GCDUtil.h
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface GCDUtil : NSObject

+ (void)runInGlobalQueue:(void (^)())queue;

+ (void)runInMainQueue:(void (^)())queue;

+ (void)runAfterSecs:(float)secs block:(void (^)())block;

@end
