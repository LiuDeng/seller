//
//  AppStaticValue.h
//  new_supply
//
//  Created by 余文华 on 15/7/7.
//  Copyright (c) 2015年 bysunnet. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AppStaticValue : NSObject

#pragma mark - 布局
extern int kCellPadding;           // 首尾上下 间距

extern int kCellControlPointX;   // 同 kCellPadding
extern int kCellControlPointY;   // 同上

extern int kCellHeight;
extern int kCellHeightHigh;
extern int kCellHeightSmall;

extern int kCellLogoHeight;        // 默认
extern int kCellLogoHeightBig;     // 大图
extern int kCellLogoHeightSmall;   // 小图

extern int kCellSpace;              // 控件 间距 (默认) 同 kCellPadding
extern int kCellSpaceHigh;
extern int kCellSpaceSmall;

extern int kCellTitleWidth;
extern int kCellTitleHeight;

extern int kCellButtonWidth;
extern int kCellButtonHeight;
extern int kCellButtonHeightHigh;
extern int kCellButtonHeightSmall;

extern int kCellIconWidht;
extern int kCellIconHeight;

extern int kCellIndicatorWidth;
extern int kCellIndicatorHeight;

extern int kCellInputWidth;
extern int kCellInputHeight;

#pragma mark - UI
///设备宽高
#define DEVICE_HEIGHT   ([[UIScreen mainScreen]bounds].size.height)
#define DEVICE_WIDTH    ([[UIScreen mainScreen]bounds].size.width)
#define DEVICE_SCALE    (DEVICE_WIDTH * 1.0f / 320)

@end
