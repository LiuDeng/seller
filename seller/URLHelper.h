//
//  URLHelper.h
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface URLHelper : NSObject

+ (instancetype)getInstance;

- (NSString *)hostURL:(NSString*)hostUrl;
- (NSString*)apiHostURL;
- (NSString*)baseURL;

- (NSString*)restApiURL:(NSString*)relativeURL;

- (NSString*)imageURL:(NSString*)fid;
- (NSString*)imageURL300:(NSString*)fid;

- (NSString*)imageHeader50:(NSString*)fid;
- (NSString*)imageHeader80:(NSString*)fid;

- (NSString*)imageIM300:(NSString*)fid;
- (NSString*)imageIM:(NSString*)fid;

- (NSString*)audioURL:(NSString*)fid;

//商品详情
- (NSString*)supplyURL:(NSString*)sid;//Web

//订单详情
- (NSString*)orderURL:(NSString*)oid;//Web

// 平台发货说明
- (NSString*)platformDispatchDescriptionURL;

//微信推送
- (NSString *)messageURLWithOpneid:(NSString *)openid buyerid:(NSString *)buyerid;


- (NSString*)appURL;


//Web
- (NSString*)appReviewURL;

//GET
- (NSString*)registrationProtocolUrl;

//GET
- (NSString*)commodityManagementUrl;

- (NSString*)logisticsURL;



@end
