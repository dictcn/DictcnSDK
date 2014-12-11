//
//  DCSplitResult.h
//  SDKDemo
//
//  Created by Zhuwei on 14-9-12.
//  Copyright (c) 2014年 Zhuwei. All rights reserved.
//

#import <Foundation/Foundation.h>


/**
 分词结果集
 
 */
@interface DCSplitResult : NSObject

/** 分到的单词 */
@property (nonatomic, strong)   NSString*   key;

/** 该词的权重 */
@property (nonatomic, assign)   NSUInteger  weight;

/** 分到的单词在分词文本中的起始位置 */
@property (nonatomic, assign)   NSUInteger  start;

/** 分到的单词在分词文本中的结束位置的下一位 */
@property (nonatomic, assign)   NSUInteger  end;

/** 分词结果的相关词条 key1 \n key2 \n.... */
@property (nonatomic, strong)   NSString*   relatedKeys;

/** 分词是否成功标志 */
@property (nonatomic, assign)   BOOL        isSplited;

@end
