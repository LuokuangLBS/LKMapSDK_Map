//
//  LKCircleRenderer.h
//  LKMapSDK_Map
//
//  Created by hao on 2020/1/14.
//  Copyright © 2020 luokung. All rights reserved.
//

#import "LKOverlayPathRenderer.h"
#import "LKCircle.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * 圆形渲染器
 */
@interface LKCircleRenderer : LKOverlayPathRenderer

/// 关联的circle
@property (nonatomic, strong, readonly) LKCircle *circle;

/**
 * 根据指定圆生成对应的Renderer
 * @param circle circle
 * @return 生成的Renderer
 */
- (instancetype)initWithCircle:(LKCircle *)circle;
@end

NS_ASSUME_NONNULL_END
