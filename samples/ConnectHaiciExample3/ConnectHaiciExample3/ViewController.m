//
//  ViewController.m
//  ConnectHaiciExample3
//
//  Created by Zhuwei on 14-10-10.
//  Copyright (c) 2014年 Zhuwei. All rights reserved.
//

#import "ViewController.h"
#import "NSAttributedString+Attributes.h"
#import <DictcnSDK/DictcnSDK.h>

@interface ViewController (PRIVATE)

@end

@implementation ViewController {
}

- (void)viewDidLoad {
    [super viewDidLoad];
    //注册客户端跳转地址
    [[DCHaiciManager sharedHaiciManager] registerSDKWithId:@"sdk1" secret:@"c685441980325f0596463f96dce98f1f" backUrl:@"ConnectHaiciExample3:"];
    
    //初始化文本控件
    NSString* text = @"1.体验最佳：无需跳转界面，只需加入很小的SDK，即可在应用内弹窗展示所查字词的内容。\n2.词典最全最好：不再需要到处寻找好词典。除海词自身的词典之外，海词还提供国内最大量的各大权威出版社独家授权的各种类型印刷版词典，供用户选择、配置查询。\n3.联合查询：查不到的词，用户不再需要到处去查阅。海词独创联合查词SDK，可以把用户所查的词，在海词已合作的最大量的权威词典中，检索一遍，然后推荐给用户哪些权威词典中，含有所查询的字词，而且用户只需下载配置，即可直接在合作应用内查询了。\n4.功能齐全：合作应用也无需配套开发词典相关的额外功能。\naahed to be blurbed as the newest, the biggest and the best dictionary";
    NSMutableAttributedString* attrString = [[NSMutableAttributedString alloc] initWithString:text];
    [attrString setFont:[UIFont systemFontOfSize:18]];
    self.textView.attributeText = attrString;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)viewDidAppear:(BOOL)animated {
    [super viewDidAppear:animated];
    
    [self checkingClient];
}



#pragma mark - private methods

/**
 检查客户端
 
 */
- (void)checkingClient {
    //检查客户端安装
    if([[DCHaiciManager sharedHaiciManager] hasInstalledClient]) {
        //判断是否连接客户端
        if(![[DCHaiciManager sharedHaiciManager] isConnected]) {
            //尝试连接客户端
            [[DCHaiciManager sharedHaiciManager] connectClientWithCompletedBlock:^(BOOL successed) {
                //如果客户端未启动服务就开启服务
                if(!successed) {
                    //连接不成功去启动海词客户端服务
                    [[DCHaiciManager sharedHaiciManager] startHaiciClientService];
                }
            }];
        }
        
    } else {
        UIAlertView* alert = [[UIAlertView alloc] initWithTitle:@"温馨提醒" message:@"开启词典功能，请安装海词词典？" delegate:self cancelButtonTitle:@"取消" otherButtonTitles:@"安装", nil];
        [alert show];
    }
}
@end
