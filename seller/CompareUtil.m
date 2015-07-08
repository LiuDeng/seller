//
//  CompareUtil.m
//  new_supply
//
//  Created by 王飞 on 15-4-7.
//  Copyright (c) 2015年 wfpb. All rights reserved.
//

#import "CompareUtil.h"

@implementation CompareUtil

+ (BOOL)compareString:(NSString*)stringA toString:(const NSString*)stringB
{
    if (stringA == stringB) {
        return YES;
    }
    
    if (stringA.length == 0 && stringB.length == 0) {
        return YES;
    }
    
    if (stringA == nil || stringB == nil) {
        return NO;
    }
    
    return [stringB isEqualToString:stringA];
}

+ (BOOL)compareNumber:(NSNumber*)numberA toNumber:(NSNumber*)numberB
{
    if (numberA == numberB) {
        return YES;
    }
    
    if (numberA == nil || numberB == nil) {
        return NO;
    }
    
    return [numberA isEqualToNumber:numberB];
}

+ (BOOL)compareArray:(NSArray*)arrayA toArray:(NSArray*)arrayB
{
    if (arrayA == arrayB) {
        return YES;
    }
    
    if (arrayA == nil || arrayB == nil) {
        return NO;
    }
    
    if (arrayA.count != arrayB.count) {
        return NO;
    }
    
    for (id obj in arrayA) {
        NSUInteger index = [arrayA indexOfObject:obj];
        id objB = [arrayB objectAtIndex:index];
        if (![obj isEqual:objB]) {
            return NO;
        }
    }
    
    return YES;
}

@end
