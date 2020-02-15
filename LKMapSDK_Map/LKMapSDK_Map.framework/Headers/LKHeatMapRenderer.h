//
//  LKHeatMapRenderer.h
//  LKMapSDK_Map
//
//  Created by hao on 2020/1/14.
//  Copyright © 2020 luokung. All rights reserved.
//

#import "LKOverlayRenderer.h"
#import "LKHeatMap.h"

NS_ASSUME_NONNULL_BEGIN

/**
 * 热力图渲染器
 */
@interface LKHeatMapRenderer : LKOverlayRenderer

/// 关联的LKHeatMap
@property (nonatomic, strong, readonly) LKHeatMap *heatMap;

/**
 * 根据指定的LKHeatMap生成一个热力图渲染器
 * @param heatMap 指定LKHeatMap
 * @return 热力图渲染器
 */
- (instancetype)initWithHeatMap:(LKHeatMap *)heatMap;

@end

NS_ASSUME_NONNULL_END
