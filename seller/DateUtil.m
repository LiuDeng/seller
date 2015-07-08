//
//  DateUtil.m
//  new_supply
//
//  Created by wfpb on 15/6/13.
//  Copyright (c) 2015年 bysunnet. All rights reserved.
//

#import "DateUtil.h"

@implementation DateUtil

+ (NSTimeInterval)now {
    return [[NSDate date] timeIntervalSince1970]*1000.0f;
}

@end
