//
//  LKPolygonRenderer.h
//  LKMapSDK_Map
//
//  Created by hao on 2020/1/11.
//  Copyright © 2020 luokung. All rights reserved.
//

#import "LKOverlayPathRenderer.h"
#import "LKPolygon.h"

NS_ASSUME_NONNULL_BEGIN
/// 面渲染器
@interface LKPolygonRenderer : LKOverlayPathRenderer

/// 关联的polygon
@property (nonatomic, strong, readonly) LKPolygon *polygon;

/**
 * 根据指定的多边形生成一个多边形Renderer
 * @param polygon polygon 指定的多边形数据对象
 * @return 新生成的多边形Renderer
 */
- (instancetype)initWithPolygon:(LKPolygon *)polygon;
@end

NS_ASSUME_NONNULL_END
