#import <UIKit/UIKit.h>
#import <LKMapSDK_Base/LKMapSDK_Base.h>
#import "LKFoundation.h"
#import "LKMapCamera.h"
#import "LKOverlayRenderer.h"

NS_ASSUME_NONNULL_BEGIN

@class LKAnnotationView;
@class LKAnnotationImage;
@class LKUserLocation;
@class LKPolyline;
@class LKPolygon;
@class LKShape;
@class LKCalloutView;
@class LKMapCustomStyleOptions;

@protocol LKMapViewDelegate;
@protocol LKAnnotation;
@protocol LKOverlay;

/// 比例尺、罗盘、logo等控件在地图上的位置
typedef NS_ENUM(NSUInteger, LKOrnamentPosition) {
    
    /// 左上角
    LKOrnamentPositionTopLeft = 0,
    
    /// 右上角
    LKOrnamentPositionTopRight,
    
    /// 左下角
    LKOrnamentPositionBottomLeft,
    
    /// 右下角
    LKOrnamentPositionBottomRight,
};

/// 是否显示控件
typedef NS_ENUM(NSInteger, LKOrnamentVisibility) {
    
    /// 自适应地图
    LKOrnamentVisibilityAdaptive,
    
    /// 始终隐藏
    LKOrnamentVisibilityHidden,
    
    /// 始终显示
    LKOrnamentVisibilityVisible
};

/// 当前位置跟踪模式
typedef NS_ENUM(NSUInteger, LKUserTrackingMode) {
    
    /// 地图不跟随当前位置
    LKUserTrackingModeNone = 0,
    
    /// 地图跟随当前位置。当拖动地图时，变为 `LKUserTrackingModeNone` 模式
    LKUserTrackingModeFollow,
   
    /// 地图跟随用户位置和方向。方向显示为扇形。当拖动地图时，该模式失效。当旋转地图时，变为`LKUserTrackingModeFollow`模式
    LKUserTrackingModeFollowWithHeading,
    
    /// 地图跟随用户位置和方向，方向显示为罗盘形。当拖动地图时，该模式失效。当旋转地图时，变为`LKUserTrackingModeFollow`模式
    LKUserTrackingModeFollowWithCourse,
};


LK_EXPORT
/// 地图视图类
@interface LKMapView : UIView

/// 代理
@property(nonatomic, weak, nullable) id<LKMapViewDelegate> delegate;

/// 地图类型，默认LKMapTypeStandard
@property (nonatomic, assign, readonly) LKMapType mapType;

/// 是否显示缩放按钮，默认NO
@property (nonatomic, assign) BOOL showZoomBar;

/// 缩放按钮位置， 默认LKOrnamentPositionBottomRight
@property (nonatomic, assign) LKOrnamentPosition zoomBarPosition;

/// 是否显示比例尺，默认NO
@property (nonatomic, assign) BOOL showScaleBar;

/// 比例尺位置， 默认LKOrnamentPositionTopLeft
@property (nonatomic, assign) LKOrnamentPosition scaleBarPosition;

/// 是否显示指南针，默认LKOrnamentVisibilityAdaptive
@property (nonatomic, assign) LKOrnamentVisibility compassViewVisiblity;

/// 指南针位置，默认LKOrnamentPositionTopRight
@property (nonatomic, assign) LKOrnamentPosition compassViewPosition;

/// 易图通logo位置，默认LKOrnamentPositionBottomLeft
@property (nonatomic, assign) LKOrnamentPosition logoViewPosition;

/**
 * 是否显示当前位置。默认NO
 *
 * @note 该属性仅控制是否显示用户位置，不保证在可视范围内，但可以设置 `userLocationVisible` 为`YES`来实现
 * @note 确保在`Info.plist` 中设置了`NSLocationWhenInUseUsageDescription` 或`NSLocationAlwaysUsageDescription`
 * @note 如果自己实现location manager，请确保设置 `locationManager`之后在使用`showsUserLocation`
 */
@property (nonatomic, assign) BOOL showsUserLocation;

/// 是否将当前位置显示在可视范围之内，默认NO
@property (nonatomic, assign, readonly, getter=isUserLocationVisible) BOOL userLocationVisible;

/// 当前位置
@property (nonatomic, readonly, nullable) LKUserLocation *userLocation;

/// 当前位置追踪模式。默认LKUserTrackingModeNone
@property (nonatomic, assign) LKUserTrackingMode userTrackingMode;

/// 是否显示方向指示条。默认NO
@property (nonatomic, assign) BOOL showsUserHeadingIndicator;

/// 是否允许所有手势。默认YES
@property(nonatomic, getter=isAllGesturesEnabled) BOOL allGesturesEnabled;

/// 是否允许缩放手势。默认YES
@property(nonatomic, getter=isZoomEnabled) BOOL zoomEnabled;

/// 是否允许滚动手势。默认YES
@property(nonatomic, getter=isScrollEnabled) BOOL scrollEnabled;

/// 是否允许旋转手势。默认YES
@property(nonatomic, getter=isRotateEnabled) BOOL rotateEnabled;

/// 是否允许倾斜手势。默认YES
@property(nonatomic, getter=isPitchEnabled) BOOL pitchEnabled;

/// 地图中心地理坐标
@property (nonatomic) CLLocationCoordinate2D centerCoordinate;

/// 缩放级别。默认8
@property (nonatomic) double zoomLevel;

/// 最小缩放级别。最小1，默认1
@property (nonatomic) double minimumZoomLevel;

/// 最大缩放级别。最大20，默认值20
@property (nonatomic) double maximumZoomLevel;

/**
 * 地图方向。取值0到359.9，相对真北方向逆时针旋转地图
 * 比如：设置为90，逆时针旋转地图90度；设置为180，逆时针旋转地图180度
 */
@property (nonatomic) CLLocationDirection direction;

/// 当前地图的经纬度范围，设定的该范围可能会被调整为适合地图窗口显示的范围
@property (nonatomic) LKCoordinateRegion region;

/// 限制地图的显示范围（地图状态改变时，该范围不会在地图显示范围外。设置成功后，会调整地图显示该范围）
@property (nonatomic) LKCoordinateRegion limitMapRegion;

/// 地图显示区域
@property (nonatomic) LKCoordinateBounds visibleCoordinateBounds;

/// 限制地图显示区域
@property (nonatomic) LKCoordinateBounds limitVisibleCoordinateBounds;

/// 地图logo、指南针、比例尺、缩放按钮偏移值。需要同时设置automaticallyAdjustsContentInset为NO。
@property (nonatomic, assign) UIEdgeInsets contentInset;

/// 是否自动调整地图logo、指南针、比例尺、缩放按钮偏移值。默认YES，如果设置为YES，这些控件将不会被navigation bars, tab bars, toolbars遮盖
@property (assign) BOOL automaticallyAdjustsContentInset;

/// 标注数组
@property (nonatomic, readonly, nullable) NSArray<id <LKAnnotation>> *annotations;

/// 可视范围内的标注数组
@property (nonatomic, readonly, nullable) NSArray<id <LKAnnotation>> *visibleAnnotations;

/// 选中的标注数组
@property (nonatomic, copy) NSArray<id <LKAnnotation>> *selectedAnnotations;

/// 覆盖物数组
@property (nonatomic, readonly, nonnull) NSArray<id <LKOverlay>> *overlays;

/// 相机
@property (nonatomic, copy) LKMapCamera *camera;

/**
 * 设置地图类型
 *
 * @param mapType 地图类型
 */
- (void)setMapType:(LKMapType)mapType;

/// 是否开启自定义样式, 默认NO
@property (nonatomic, assign) BOOL customMapStyleEnabled;

/**
 * 自定义地图样式
 *
 * @param styleOptions 自定义样式
 */
- (void)setCustomMapStyleOptions:(LKMapCustomStyleOptions *)styleOptions;


#pragma mark 添加或移除标注

/**
 * 添加标注
 *
 * @param annotation 标注
 */
- (void)addAnnotation:(id <LKAnnotation>)annotation;

/**
 * 添加一组标注
 *
 * @param annotations 一组标注
 */
- (void)addAnnotations:(NSArray<id <LKAnnotation>> *)annotations;

/**
 * 移除标注
 *
 * @param annotation 标注
 */
- (void)removeAnnotation:(id <LKAnnotation>)annotation;

/**
 * 移除一组标注
 *
 * @param annotations 一组标注
 */
- (void)removeAnnotations:(NSArray<id <LKAnnotation>> *)annotations;

/**
 * 标注视图
 *
 * @param annotation 标注
 */
- (nullable LKAnnotationView *)viewForAnnotation:(id <LKAnnotation>)annotation;

/**
 * 获取标注视图
 *
 * @param identifier 重用标识，必须唯一
 * @return 标注视图或nil
 */
- (nullable __kindof LKAnnotationView *)dequeueReusableAnnotationViewWithIdentifier:(NSString *)identifier;

/**
 * 获取矩形范围内的一组标注
 *
 * @param rect 矩形
 * @return 一组标注
 */
- (nullable NSArray<id <LKAnnotation>> *)visibleAnnotationsInRect:(CGRect)rect;


#pragma mark 选中或取消选中标注

/**
 * 选中标注
 *
 * @param annotation 标注
 * @param animated 是否允许动画
 * @param completion 动画结束回调
 */
- (void)selectAnnotation:(id <LKAnnotation>)annotation animated:(BOOL)animated completionHandler:(nullable void (^)(void))completion;

/**
 * 选中标注
 *
 * @param annotation 标注
 * @param moveIntoView 要移动到的视图
 * @param animateSelection 是否允许动画
 * @param completion 动画结束回调
 */
- (void)selectAnnotation:(id <LKAnnotation>)annotation moveIntoView:(BOOL)moveIntoView animateSelection:(BOOL)animateSelection completionHandler:(nullable void (^)(void))completion;

/**
 * 取消选中标注
 *
 * @param annotation 标注
 * @param animated 是否允许动画
 */
- (void)deselectAnnotation:(nullable id <LKAnnotation>)annotation animated:(BOOL)animated;


#pragma mark 添加或移除覆盖物

/**
 * 添加覆盖物
 *
 * @param overlay 覆盖物
 */
- (void)addOverlay:(id <LKOverlay>)overlay;

/**
 * 添加一组覆盖物
 *
 * @param overlays 一组覆盖物
 */
- (void)addOverlays:(NSArray<id <LKOverlay>> *)overlays;

/**
 * 移除覆盖物
 *
 * @param overlay 覆盖物
 */
- (void)removeOverlay:(id <LKOverlay>)overlay;

/**
 * 移除一组覆盖物
 *
 * @param overlays 一组覆盖物
 */
- (void)removeOverlays:(NSArray<id <LKOverlay>> *)overlays;

/**
 * 在指定的Overlay上面插入一个overlay
 * @param overlay 待添加的Overlay
 * @param sibling 用于指定相对位置的Overlay
 */
- (void)insertOverlay:(id <LKOverlay>)overlay aboveOverlay:(id <LKOverlay>)sibling;

/**
 * 在指定的Overlay下面插入一个overlay
 * @param overlay 待添加的Overlay
 * @param sibling 用于指定相对位置的Overlay
 */
- (void)insertOverlay:(id <LKOverlay>)overlay belowOverlay:(id <LKOverlay>)sibling;

/**
 * 查找指定overlay对应的Renderer。如果尚未创建，返回nil
 *
 * @param overlay 指定的overlay
 * @return 指定overlay对应的Renderer
 */
- (nullable LKOverlayRenderer *)rendererForOverlay:(id <LKOverlay>)overlay;

#pragma mark 用户位置

/**
 * 设置当前位置追踪模式
 *
 * @param mode 模式
 * @param animated 是否动画
 * @param completion 回调
 */
- (void)setUserTrackingMode:(LKUserTrackingMode)mode animated:(BOOL)animated completionHandler:(nullable void (^)(void))completion;

/**
 * 根据最后位置更新用户位置标注
 */
- (void)updateUserLocationAnnotationView;

/**
 * 根据最后位置更新用户位置标注，并指定动画时长
 *
 * @param duration 动画时长
 */
- (void)updateUserLocationAnnotationViewAnimatedWithDuration:(NSTimeInterval)duration;

#pragma mark 地图位置、级别、朝向

/**
 * 设置地图中心地理坐标
 *
 * @param coordinate 地理坐标
 * @param animated 是否允许动画
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)coordinate animated:(BOOL)animated;

/**
 * 设置地图中心地理坐标和缩放级别
 *
 * @param centerCoordinate 地理坐标
 * @param zoomLevel 缩放级别
 * @param animated 是否允许动画
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate zoomLevel:(double)zoomLevel animated:(BOOL)animated;

/**
 * 设置地图中心地理坐标、缩放级别和方向
 *
 * @param centerCoordinate 地理坐标
 * @param zoomLevel 缩放级别
 * @param direction 地图方向
 * @param animated 是否允许动画
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate zoomLevel:(double)zoomLevel direction:(CLLocationDirection)direction animated:(BOOL)animated;

/**
 * 设置地图中心地理坐标、缩放级别和方向
 *
 * @param centerCoordinate 地理坐标
 * @param zoomLevel 缩放级别
 * @param direction 地图方向
 * @param animated 是否允许动画
 * @param completion 动画结束回调
 */
- (void)setCenterCoordinate:(CLLocationCoordinate2D)centerCoordinate zoomLevel:(double)zoomLevel direction:(CLLocationDirection)direction animated:(BOOL)animated completionHandler:(nullable void (^)(void))completion;

/**
 * 设置缩放级别
 *
 * @param zoomLevel 缩放级别
 * @param animated 是否允许动画
 */
- (void)setZoomLevel:(double)zoomLevel animated:(BOOL)animated;

/**
 * 减小缩放级别
 */
- (void)zoomOut;

/**
 * 增加缩放级别
 */
- (void)zoomIn;

/**
 * 增加、减少指定缩放级别
 *
 * @param zoom 级别
 */
- (void)zoomBy:(double)zoom;

/**
 * 设置地图方向。取值0到359.9，相对真北方向逆时针旋转地图。比如：设置为90，逆时针旋转地图90度；设置为180，逆时针旋转地图180度
 *
 * @param direction 地图方向
 * @param animated 是否允许动画
 */
- (void)setDirection:(CLLocationDirection)direction animated:(BOOL)animated;

/**
 * 重置地图方向
 */
- (void)resetNorth;

/**
 * 重置地图位置
 */
- (void)resetPosition;

/**
 * 设定当前地图的显示范围
 *
 * @param region 要设定的地图范围，用经纬度的方式表示
 * @param animated 是否采用动画效果
 */
- (void)setRegion:(LKCoordinateRegion)region animated:(BOOL)animated;

/**
 * 设置可视范围
 *
 * @param bounds 范围
 * @param animated 是否允许动画
 */
- (void)setVisibleCoordinateBounds:(LKCoordinateBounds)bounds animated:(BOOL)animated;

/**
 * 设置可视范围
 *
 * @param bounds 范围
 * @param insets 偏移
 * @param animated 是否允许动画
 * @param completion 动画完成后回调
 */
- (void)setVisibleCoordinateBounds:(LKCoordinateBounds)bounds edgePadding:(UIEdgeInsets)insets animated:(BOOL)animated completionHandler:(nullable void (^)(void))completion;

/**
 * 显示一组标注
 *
 * @param annotations 标注数组
 * @param animated 是否允许动画
 */
- (void)showAnnotations:(NSArray<id <LKAnnotation>> *)annotations animated:(BOOL)animated;

/**
 * 显示一组标注
 *
 * @param annotations 标注数组
 * @param insets 偏移
 * @param animated 是否允许动画
 * @param completion 动画完成回调
 */
- (void)showAnnotations:(NSArray<id <LKAnnotation>> *)annotations edgePadding:(UIEdgeInsets)insets animated:(BOOL)animated completionHandler:(nullable void (^)(void))completion;

/**
 * 截屏
 *
 @return 截图或nil
 */
- (UIImage *)snapshot;

/**
 * 截屏指定区域
 *
 * @param rect 指定区域
 * @return 截图或nil
 */
- (UIImage *)snapshotWithRect:(CGRect)rect;

/**
 * 地图偏移
 *
 * @param contentInset 偏移
 * @param animated 是否允许动画
 * @param completion 动画结束回调
 */
- (void)setContentInset:(UIEdgeInsets)contentInset animated:(BOOL)animated completionHandler:(nullable void (^)(void))completion;


#pragma mark 坐标转换

/**
 * 视图坐标转换为地理坐标
 *
 * @param point 视图坐标
 * @param view 视图
 * @return 地理坐标
 */
- (CLLocationCoordinate2D)convertPoint:(CGPoint)point toCoordinateFromView:(nullable UIView *)view;

/**
 * 地理坐标转换为视图坐标
 *
 * @param coordinate 地理坐标
 * @param view 视图
 * @return 视图坐标
 */
- (CGPoint)convertCoordinate:(CLLocationCoordinate2D)coordinate toPointToView:(nullable UIView *)view;

/**
 * 矩形转换为地理边界
 *
 * @param rect 矩形
 * @param view 视图
 * @return 地理边界
 */
- (LKCoordinateBounds)convertRect:(CGRect)rect toCoordinateBoundsFromView:(nullable UIView *)view;

/**
 * 地理边界转换为矩形
 *
 * @param bounds 地理边界
 * @param view 视图
 * @return 矩形
 */
- (CGRect)convertCoordinateBounds:(LKCoordinateBounds)bounds toRectToView:(nullable UIView *)view;

/**
 * 一个坐标点代表的距离
 *
 * @param latitude 纬度
 * @return 距离，单位：米
 */
- (CLLocationDistance)metersPerPointAtLatitude:(CLLocationDegrees)latitude;
@end

NS_ASSUME_NONNULL_END
