//
//  LKMapCustomStyleOptions.h
//  LKMapSDK_Map
//
//  Created by hao on 2020/2/6.
//  Copyright © 2020 luokung. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
/// 自定义地图参数
@interface LKMapCustomStyleOptions : NSObject

/// 自定义样式文件路径。通过id加载失败时，将会从本地加载此路径下的自定义样式
@property(nonatomic, copy, nullable)NSString *styleFilePath;

/// 自定义样式id，从官网获取 https://lbs.luokuang.com/console/customMap
@property (nonatomic, copy, nullable) NSString *styleId;

@end

NS_ASSUME_NONNULL_END
