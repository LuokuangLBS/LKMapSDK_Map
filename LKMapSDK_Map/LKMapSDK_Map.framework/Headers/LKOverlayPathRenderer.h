//
//  LKOverlayPathRenderer.h
//  LKMapSDK_Map
//
//  Created by hao on 2020/1/11.
//  Copyright © 2020 luokung. All rights reserved.
//

#import "LKOverlayRenderer.h"
#import "LKLineDrawType.h"

NS_ASSUME_NONNULL_BEGIN

@interface LKOverlayPathRenderer : LKOverlayRenderer

/// 填充色。默认黑色
@property (nonatomic, strong) UIColor *fillColor;

/// 画笔色。默认黑色
@property (nonatomic, strong) UIColor *strokeColor;

/// 画笔宽度。默认0
@property (nonatomic, assign) CGFloat lineWidth;

/// 线连接样式。默认LKLineJoinMiter
@property (nonatomic, assign) LKLineJoin lineJoinType;

/// 线尾样式。默认LKLineCapButt
@property (nonatomic, assign) LKLineCap lineCapType;

/// 线连接角最大长度。默认10
@property (nonatomic, assign) CGFloat miterLimit;

/// 虚线样式
@property (nonatomic, assign) LKLineDash lineDashType;
@end

NS_ASSUME_NONNULL_END
