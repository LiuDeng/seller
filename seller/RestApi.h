//
//  RestApi.h
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef int8_t HttpMethods;

enum : HttpMethods {
    kHttpGet = 1,
    kHttpPost = 2,
    kHttpDelete = 3,
    kHttpPut = 4,
};

@interface RestApi : NSObject

- (id)initWithURL:(NSString *)url httpMethod:(HttpMethods)httpMethod;

- (void)call;
- (void)call:(BOOL)async;
- (void)call:(BOOL)async timeout:(float)timeout;

- (void)cancel;

- (void)setRequestHeader:(NSMutableURLRequest *)request;

- (void)doSuccess:(id)responseObject;

- (void)raiseException:(NSString *)exception;

@property (nonatomic, readonly) BOOL isCancelled;
@property (nonatomic, readonly) BOOL isTimeout;
@property (nonatomic, readonly) BOOL isSuccessed;
@property (nonatomic, readonly) BOOL isCompleted;
@property (nonatomic, strong, readonly) NSError* error;

#pragma mark - Subclassing methods

- (NSData*)requestData;

- (NSDictionary*)queryParameters;

- (void)onSuccessed;

- (void)onFailed;

- (void)onCancelled;

- (void)onTimeout;

- (void)onError:(NSError*)error;

@end
