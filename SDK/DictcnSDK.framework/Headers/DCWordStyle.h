//
//  DCWordStyle.h
//  SDKDemo
//
//  Created by Zhuwei on 14-9-12.
//  Copyright (c) 2014年 Zhuwei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 单词展示样式
 
 */
@interface DCWordStyle : NSObject

/** 释义文本颜色 */
@property (nonatomic, strong)   UIColor*    defineTextColor;

/** 释义宽度 */
@property (nonatomic, assign)   float       defineWidth;

/** 释义的字体 */
@property (nonatomic, strong)   UIFont*     defineTextFont;

/** 释义的行间距 */
@property (nonatomic, assign)   float       defineLineSpace;

@end
