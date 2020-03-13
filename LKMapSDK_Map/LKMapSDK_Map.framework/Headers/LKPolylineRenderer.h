//
//  LKPolylineRenderer.h
//  LKMapSDK_Map
//
//  Created by hao on 2020/1/11.
//  Copyright © 2020 luokung. All rights reserved.
//

#import "LKOverlayPathRenderer.h"
#import "LKPolyline.h"

NS_ASSUME_NONNULL_BEGIN

/// 线渲染器
@interface LKPolylineRenderer : LKOverlayPathRenderer

/// 关联的polyline
@property (nonatomic, strong, readonly) LKPolyline *polyline;

/// 是否开启点击选中功能。默认NO
@property (nonatomic, assign) BOOL userInteractionEnabled;

/**
 * 根据指定的polyline生成一个多段线Renderer
 * @param polyline 指定polyline
 * @return 新生成的多段线Renderer
 */
- (instancetype)initWithPolyline:(LKPolyline *)polyline;
@end

NS_ASSUME_NONNULL_END
