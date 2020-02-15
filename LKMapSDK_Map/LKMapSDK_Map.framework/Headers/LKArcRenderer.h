//
//  LKArcRenderer.h
//  LKMapSDK_Map
//
//  Created by hao on 2020/1/14.
//  Copyright © 2020 luokung. All rights reserved.
//

#import "LKOverlayPathRenderer.h"
#import "LKArc.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * 圆弧渲染器
 */
@interface LKArcRenderer : LKOverlayPathRenderer

/// 关联的LKArc
@property (nonatomic, strong, readonly) LKArc *arc;

/**
 * 根据指定的LKArc生成一个圆弧渲染器
 *
 * @param arc 指定LKArc
 * @return 圆弧渲染器
 */
- (instancetype)initWithArc:(LKArc *)arc;
@end

NS_ASSUME_NONNULL_END
