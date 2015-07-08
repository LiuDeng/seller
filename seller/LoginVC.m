//
//  LoginVC.m
//  seller
//
//  Created by mac on 15/7/8.
//  Copyright (c) 2015年 ds. All rights reserved.
//

#import "LoginVC.h"

#import "TabbarViewController.h"

#import "MacroHeader.h"

@interface LoginVC ()

@property (nonatomic, strong) UITextField *dUserTel;
@property (nonatomic, strong) UITextField *dPassword;

@end

@implementation LoginVC

- (id)init {
    if (self = [super init]) {
        self.view.backgroundColor = [UIColor whiteColor];
    }
    return self;
}

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    
    [self initUIViews];
}

- (void)initUIViews {
    // 1 - Logo
    
    // 2 - User name
    _dUserTel = [[UITextField alloc] initWithFrame:CGRectMake(kCellControlPointX, kCellControlPointY, 300, 40)];
    _dUserTel.placeholder = @"用户名";
    _dUserTel.text = @"18698894171";
    _dUserTel.borderStyle = UITextBorderStyleRoundedRect;
    [self.view addSubview:_dUserTel];
    
    // 3 - Password
    _dPassword = [[UITextField alloc] initWithFrame:CGRectMake(kCellControlPointX, 100, 300, 40)];
    _dPassword.borderStyle = UITextBorderStyleRoundedRect;
    _dPassword.placeholder = @"密码";
    _dPassword.text = @"660419";
    [self.view addSubview:_dPassword];
    
    // 4 - Login
    UIButton *loginBtn = [UIButton buttonWithType:UIButtonTypeSystem];
    [loginBtn setTitle:@"登录" forState:UIControlStateNormal];
    [loginBtn setFrame:CGRectMake(kCellControlPointX, 300, DEVICE_WIDTH-kCellControlPointX*2, kCellButtonHeight)];
    [loginBtn setBackgroundColor:[UIColor lightGrayColor]];
    [loginBtn addTarget:self action:@selector(loginEvent:) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:loginBtn];
    
    // 5 - Register
    
    // 6 - Contact
}

- (void)loginEvent:(UIButton *)sender {
    
    
    
    TabbarViewController *tabVC = [[TabbarViewController alloc] init];
    [self presentViewController:tabVC animated:YES completion:nil];
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
