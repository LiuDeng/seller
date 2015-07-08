//
//  CompareUtil.h
//  new_supply
//
//  Created by 王飞 on 15-4-7.
//  Copyright (c) 2015年 wfpb. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface CompareUtil : NSObject

+ (BOOL)compareString:(NSString*)stringA toString:(const NSString*)stringB;

+ (BOOL)compareNumber:(NSNumber*)numberA toNumber:(NSNumber*)numberB;

+ (BOOL)compareArray:(NSArray*)arrayA toArray:(NSArray*)arrayB;

@end
