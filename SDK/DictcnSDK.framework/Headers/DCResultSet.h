//
//  DCResultSet.h
//  SDKDemo
//
//  Created by Zhuwei on 14-9-12.
//  Copyright (c) 2014年 Zhuwei. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 查词结果集
 
 */
@interface DCResultSet : NSObject

/** 查询的关键词 */
@property (nonatomic, strong)       NSString*           key;

/** 查询的单词列表(内部存储了 DCStyleWord类型 ) */
@property (nonatomic, readonly)     NSMutableArray*     wordlist;

/** 相关词典的数量 */
@property (nonatomic, assign)       NSUInteger          numberOfRelatedDictionaries;

@end
