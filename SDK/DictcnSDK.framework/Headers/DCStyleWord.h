//
//  DCStyleWord.h
//  SDKDemo
//
//  Created by Zhuwei on 14-9-12.
//  Copyright (c) 2014年 Zhuwei. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 查询的单词类型
 
 */
typedef NS_ENUM(NSUInteger, DCWordLanguageType) {
    DCWordLanguageTypeEC,           //英汉词
    DCWordLanguageTypeCE,           //汉英词
    DCWordLanguageTypeCN            //汉语
};


@class DCWord;
@class DCWordStyle;
/**
 展示样式单词类型
 
 */
@interface DCStyleWord : NSObject


#pragma mark - 属性
/** 查询关键词 */
@property (nonatomic, readonly)   NSString*             key;

/** 原型关键字 */
@property (nonatomic, strong)   NSString*               prototypeKey;

/** 音标 */
@property (nonatomic, readonly)   NSString*             phoneticSymbol;

/** 网络发音唯一标识符 */
@property (nonatomic, readonly)   NSString*             audio;

/** 发音key */
@property (nonatomic, readonly)   NSString*             pronKey;

/** 释义图片数据 */
@property (nonatomic, readonly)   UIImage*              defImage;

/** 释义样式对象 */
@property (nonatomic, strong)     DCWordStyle*          style;

/** 单词语言类型 */
@property (nonatomic, assign)   DCWordLanguageType      languageType;

/** 发音URL */
@property (readonly, strong)   NSURL*                   pronURL;

/** 来自词典 */
@property (nonatomic, strong)   NSString*               appName;

#pragma mark - 初始化方法
/**
 通过数据来构造单词对象
 
 @param word:       单词对象
 
 @param style:      单词展示样式
 
 @return 返回对象
 */
- (instancetype)initWithWord:(DCWord *)word style:(DCWordStyle *)style;

/**
 示意图片
 
 */
- (UIImage *)defImageWithStyle:(DCWordStyle*)style;

@end
