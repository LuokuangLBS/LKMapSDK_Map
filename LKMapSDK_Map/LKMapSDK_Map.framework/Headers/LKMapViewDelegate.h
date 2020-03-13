#import <UIKit/UIKit.h>

#import "LKMapSDK_Map.h"
#import "LKCameraChangeReason.h"

NS_ASSUME_NONNULL_BEGIN

@class LKMapView;
@class LKOverlayRenderer;

/// 地图代理方法
@protocol LKMapViewDelegate <NSObject>

@optional

#pragma mark 标注

/**
 * 设置标注视图
 *
 * @param mapView 地图
 * @param annotation 标注
 * @return 标注视图
 */
- (nullable LKAnnotationView *)mapView:(LKMapView *)mapView viewForAnnotation:(id <LKAnnotation>)annotation;

/**
 * 添加标注视图回调
 *
 * @param mapView 地图
 * @param annotationViews 标注视图数组
 */
- (void)mapView:(LKMapView *)mapView didAddAnnotationViews:(NSArray<LKAnnotationView *> *)annotationViews;

/**
 * 选中标注视图回调
 *
 * @param mapView 地图
 * @param annotationView 选中的标注视图
 */
- (void)mapView:(LKMapView *)mapView didSelectAnnotationView:(LKAnnotationView *)annotationView;

/**
 * 取消选中标注视图回调
 *
 * @param mapView 地图
 * @param annotationView 取消选中的标注视图
 */
- (void)mapView:(LKMapView *)mapView didDeselectAnnotationView:(LKAnnotationView *)annotationView;

#pragma mark 覆盖物
/**
 * 根据overlay生成对应的Renderer
 * @param mapView 地图
 * @param overlay 指定的overlay
 * @return 生成的覆盖物Renderer
 */
- (nullable LKOverlayRenderer *)mapView:(LKMapView *)mapView rendererForOverlay:(id <LKOverlay>)overlay;

/**
 * 添加覆盖物回调
 *
 * @param mapView 地图
 * @param overlayRenderers 新添加的覆盖物
 */
- (void)mapView:(LKMapView *)mapView didAddOverlayRenderers:(NSArray<LKOverlayRenderer *> *)overlayRenderers;

#pragma mark 弹框
/**
 * 设置是否允许弹框。默认NO
 *
 * @param mapView 地图
 * @param annotation 标注
 * @return 是否允许弹出框
 */
- (BOOL)mapView:(LKMapView *)mapView annotationCanShowCallout:(id <LKAnnotation>)annotation;

/**
 * 设置弹框视图
 *
 * @param mapView 地图
 * @param annotation 标注
 * @return 弹框视图
 */
- (nullable LKCalloutView *)mapView:(LKMapView *)mapView calloutViewForAnnotation:(id <LKAnnotation>)annotation;

/**
 * 设置弹框左侧辅助视图
 *
 * 当视图（或子视图）是`UIControl`子类时，将回调 `-mapView:annotation:calloutAccessoryControlTapped:`方法
 *
 * @param mapView 地图
 * @param annotation 标注
 * @return 左侧辅助视图
 */
- (nullable UIView *)mapView:(LKMapView *)mapView leftCalloutAccessoryViewForAnnotation:(id <LKAnnotation>)annotation;

/**
 * 设置弹框右侧辅助视图
 *
 * 当视图（或子视图）是`UIControl`子类时，将回调 `-mapView:annotation:calloutAccessoryControlTapped:`方法
 *
 * @param mapView 地图
 * @param annotation 标注
 * @return 右侧辅助视图
 */
- (nullable UIView *)mapView:(LKMapView *)mapView rightCalloutAccessoryViewForAnnotation:(id <LKAnnotation>)annotation;

/**
 * 弹框辅助视图点击事件回调
 *
 * 左或右辅助视图（或子视图）是`UIControl`子类时，将回调此方法
 *
 * @param mapView 地图
 * @param annotation 标注
 * @param control 辅助视图点击事件
 */
- (void)mapView:(LKMapView *)mapView annotation:(id <LKAnnotation>)annotation calloutAccessoryControlTapped:(UIControl *)control;

/**
 * 弹框点击事件回调
 *
 * @param mapView 地图
 * @param annotation 标注
 */
- (void)mapView:(LKMapView *)mapView tapOnCalloutForAnnotation:(id <LKAnnotation>)annotation;

#pragma mark 手势事件
/**
 * 单击地图
 *
 * @param mapView 地图
 * @param coordinate 单击处地理坐标
 */
- (void)mapView:(LKMapView *)mapView onClickForCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 * 双击地图
 *
 * @param mapView 地图
 * @param coordinate 双击处地理坐标
 */
- (void)mapView:(LKMapView *)mapView onDoubleClickForCoordinate:(CLLocationCoordinate2D)coordinate;

/**
 * 长按地图
 *
 * @param mapView 地图
 * @param coordinate 长按处地理坐标
 */
- (void)mapView:(LKMapView *)mapView onLongPressForCoordinate:(CLLocationCoordinate2D)coordinate;

#pragma mark 地图视角

/**
 * 是否允许转换到新视角
 *
 * @param mapView 地图
 * @param oldCamera 手势开始时的视角，如果该方法返回 `NO`，视角将不改变
 * @param newCamera 手势完成时的视角，如果该方法返回 `YES`，将转换到新视角
 * @return 是否允许转换到新视角
 *
 * @note 只针对手势有效，通过API不会调用该方法，例如：设置`centerCoordinate` 属性
 * @note 执行手势过程中，会频繁调用该方法，所以不要在该方法中做复杂操作
 */
- (BOOL)mapView:(LKMapView *)mapView shouldChangeFromCamera:(LKMapCamera *)oldCamera toCamera:(LKMapCamera *)newCamera;


/**
 * 是否允许转换到新视角
 *
 * @param mapView 地图
 * @param oldCamera 手势开始时的视角，如果该方法返回 `NO`，视角将不改变
 * @param newCamera 手势完成时的视角，如果该方法返回 `YES`，将转换到新视角
 * @param reason 转换原因
 * @return 是否允许转换到新视角
 *
 * @note 只针对手势有效，通过API不会调用该方法，例如：设置`centerCoordinate` 属性
 * @note 执行手势过程中，会频繁调用该方法，所以不要在该方法中做复杂操作
 * @note 实现该方法后，不再调用`-mapView:shouldChangeFromCamera:toCamera:`
 */
- (BOOL)mapView:(LKMapView *)mapView shouldChangeFromCamera:(LKMapCamera *)oldCamera toCamera:(LKMapCamera *)newCamera reason:(LKCameraChangeReason)reason;

/**
 * 地图区域即将要改变
 *
 * @param mapView 地图
 * @param animated 是否动画
 */
- (void)mapView:(LKMapView *)mapView regionWillChangeAnimated:(BOOL)animated;

/**
 * 地图区域即将要改变
 *
 * @param mapView 地图
 * @param animated 是否动画
 * @param reason 改变原因
 *
 * @note 实现该方法后，不再调用`-mapView:regionWillChangeAnimated:`

 */
- (void)mapView:(LKMapView *)mapView regionWillChangeWithReason:(LKCameraChangeReason)reason animated:(BOOL)animated;

/**
 * 地图区域正在改变
 *
 * @param mapView 地图
 *
 * @note 手势及调用API方法，例如：`-[LKMapView setCamera:animated:]，都会调用该方法
 * @note 该方法可能会在 `-mapViewDidFinishLoadingMap:` 之前被调用
 * @note 由于会频繁调用该方法，所以不要做复杂操作
 */
- (void)mapViewRegionIsChanging:(LKMapView *)mapView;

/**
 * 地图区域正在改变
 *
 * @param mapView 地图
 * @param reason 改变原因
 *
 * @note 手势及调用API方法，例如：`-[LKMapView setCamera:animated:]，都会调用该方法
 * @note 该方法可能会在 `-mapViewDidFinishLoadingMap:` 之前被调用
 * @note 由于会频繁调用该方法，所以不要做复杂操作
 * @note 实现该方法后，不再调用`-mapViewRegionIsChanging:`
 */
- (void)mapView:(LKMapView *)mapView regionIsChangingWithReason:(LKCameraChangeReason)reason;

/**
 * 地图区域已经改变
 *
 * @param mapView 地图
 * @param animated 是否动画
 *
 * @note 该方法可能会在 `-mapViewDidFinishLoadingMap:` 之前被调用
 */
- (void)mapView:(LKMapView *)mapView regionDidChangeAnimated:(BOOL)animated;

/**
 * 地图区域已经改变
 *
 * @param mapView 地图
 * @param animated 是否动画
 * @param reason 改变原因
 *
 * @note 该方法可能会在 `-mapViewDidFinishLoadingMap:` 之前被调用
 * @note 实现该方法后，不再调用`-mapView:regionDidChangeAnimated:`
 */
- (void)mapView:(LKMapView *)mapView regionDidChangeWithReason:(LKCameraChangeReason)reason animated:(BOOL)animated;

#pragma mark 地图加载状态

/**
 * 地图开始加载
 *
 * @param mapView 地图
 */
- (void)mapViewWillStartLoadingMap:(LKMapView *)mapView;

/**
 * 地图完成加载
 *
 * @param mapView 地图
 */
- (void)mapViewDidFinishLoadingMap:(LKMapView *)mapView;

/**
 * 地图加载失败
 *
 * @param mapView 地图
 * @param error 失败原因
 */
- (void)mapViewDidFailLoadingMap:(LKMapView *)mapView withError:(NSError *)error;

/**
 * 地图开始渲染
 */
- (void)mapViewWillStartRenderingMap:(LKMapView *)mapView;

/**
 * 地图完成渲染
 */
- (void)mapViewDidFinishRenderingMap:(LKMapView *)mapView fullyRendered:(BOOL)fullyRendered;

/**
 * 地图开始重绘
 *
 * @param mapView 地图
 * @note 该方法调用十分频繁，请不要在该方法中做复杂操作
 */
- (void)mapViewWillStartRenderingFrame:(LKMapView *)mapView;

/**
 * 地图完成重绘
 *
 * @param mapView 地图
 * @note 该方法调用十分频繁，请不要在该方法中做复杂操作
 */
- (void)mapViewDidFinishRenderingFrame:(LKMapView *)mapView fullyRendered:(BOOL)fullyRendered;

/**
 * 地图进入空闲状态
 *
 * @param mapView 地图
 */
- (void)mapViewDidBecomeIdle:(LKMapView *)mapView;


#pragma mark 定位

/**
 * 定位开始
 *
 * @param mapView 地图
 */
- (void)mapViewWillStartLocatingUser:(LKMapView *)mapView;

/**
 * 定位结束
 *
 * @param mapView 地图
 */
- (void)mapViewDidStopLocatingUser:(LKMapView *)mapView;

/**
 * 位置或朝向已经更新
 *
 * @param mapView 地图
 * @param userLocation 位置
 */
- (void)mapView:(LKMapView *)mapView didUpdateUserLocation:(nullable LKUserLocation *)userLocation;

/**
 * 定位失败
 *
 * @param mapView 地图
 * @param error 失败原因，参照CLError.h
 */
- (void)mapView:(LKMapView *)mapView didFailToLocateUserWithError:(NSError *)error;

/**
 * 跟踪模式已经改变
 *
 * @param mapView 地图
 * @param mode 新的追踪模式
 * @param animated 是否动画
 */
- (void)mapView:(LKMapView *)mapView didChangeUserTrackingMode:(LKUserTrackingMode)mode animated:(BOOL)animated;
@end

NS_ASSUME_NONNULL_END
