//
//  TabbarViewController.m
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import "TabbarViewController.h"

#import "AboutMeViewController.h"
#import "OrderListViewController.h"
#import "ChatListVC.h"


@interface TabbarViewController ()

@end

@implementation TabbarViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self initVCs];
}

- (void)initVCs {
    OrderListViewController *orderVC = [[OrderListViewController alloc] init];
    orderVC.title = @"订单";
    UINavigationController *orderNav = [[UINavigationController alloc] initWithRootViewController:orderVC];
    
    ChatListVC *chatVC = [[ChatListVC alloc] init];
    chatVC.title = @"聊天";
    UINavigationController *chatNav = [[UINavigationController alloc] initWithRootViewController:chatVC];
    
    AboutMeViewController *aboutVC = [[AboutMeViewController alloc] init];
    aboutVC.title = @"我";
    UINavigationController *aboutNav = [[UINavigationController alloc] initWithRootViewController:aboutVC];
    
    self.viewControllers = @[orderNav,chatNav,aboutNav];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

/*
#pragma mark - Navigation

// In a storyboard-based application, you will often want to do a little preparation before navigation
- (void)prepareForSegue:(UIStoryboardSegue *)segue sender:(id)sender {
    // Get the new view controller using [segue destinationViewController].
    // Pass the selected object to the new view controller.
}
*/

@end
