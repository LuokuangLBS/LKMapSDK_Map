#import <UIKit/UIKit.h>

#import "LKFoundation.h"
#import "LKCalloutView.h"

NS_ASSUME_NONNULL_BEGIN

@protocol LKAnnotation;

/// 拖动状态
typedef NS_ENUM(NSUInteger, LKAnnotationViewDragState) {
    
    /// 未拖动
    LKAnnotationViewDragStateNone = 0,
    
    /// 拖动开始
    LKAnnotationViewDragStateStarting,
    
    /// 拖动中
    LKAnnotationViewDragStateDragging,
    
    /// 拖动取消
    LKAnnotationViewDragStateCanceling,
    
    /// 拖动结束
    LKAnnotationViewDragStateEnding,
};

LK_EXPORT
/// 标注视图
@interface LKAnnotationView : UIView <NSSecureCoding>

/**
 * 视图关联的标注
 * 不要直接修改该属性，当view被加入重用队列后，该值为nil
 */
@property (nonatomic, nullable) id <LKAnnotation> annotation;

/// 重用标识，必须唯一
@property (nonatomic, readonly, nullable) NSString *reuseIdentifier;

/// 标注图标
@property (nonatomic, strong, nullable) UIImage *image;


/**
 * 偏移。默认标注中心和视图中心重合
 */
@property (nonatomic) CGVector centerOffset;

/**
 * 当地图倾斜时，是否改变标注视图形状。默认NO
 * 当设置为`YES`和倾斜地图时， 标注视图头部变窄，底部变宽
 *
 * @note 如果地图上的标注视图很多时，设置`YES`将影响地图性能
 */
@property (nonatomic, assign) BOOL scalesWithViewingDistance;

/// 当地图旋转时，是否旋转标注视图。默认NO
@property (nonatomic, assign) BOOL rotatesToMatchCamera;

/// 标注视图是否被选中。 默认NO，设置为YES时，将展示弹出框
@property (nonatomic, assign, getter=isSelected) BOOL selected;

/// 是否允许交互。默认YES，设置为NO时，将忽略触摸事件，且不能被选中
@property (nonatomic, assign, getter=isEnabled) BOOL enabled;

/// 是否显示弹框。默认NO，如果实现了代理方法，将优先使用代理方法中设置的值
@property (nonatomic, assign, getter=isCanShowCallout) BOOL canShowCallout;

/// 弹框。如果实现了代理方法，将优先使用代理方法中设置的视图，不设置将使用默认弹框
@property (nonatomic, strong, nullable) LKCalloutView *calloutView;

/// 显示在弹框左侧的视图。如果实现了代理方法，将优先使用代理方法中设置的视图
@property (nonatomic, strong, nullable) UIView *leftCalloutAccessoryView;

/// 显示在弹框右侧的视图。如果实现了代理方法，将优先使用代理方法中设置的视图
@property (nonatomic, strong, nullable) UIView *rightCalloutAccessoryView;

/// 是否允许被拖动。默认 NO
@property (nonatomic, assign, getter=isDraggable) BOOL draggable;

/// 拖动状态
@property (nonatomic, readonly) LKAnnotationViewDragState dragState;


/**
 * 创建标注视图实例
 *
 * @param reuseIdentifier 重用标识，必须唯一
 * @return 标注视图实例
 */
- (instancetype)initWithReuseIdentifier:(nullable NSString *)reuseIdentifier;

/**
 * 创建标注视图实例
 *
 * @param annotation 标注
 * @param reuseIdentifier 重用标识，必须唯一
 * @return 标注视图实例
 */
- (instancetype)initWithAnnotation:(nullable id<LKAnnotation>)annotation reuseIdentifier:(nullable NSString *)reuseIdentifier;

/**
 * 标注视图从重用队列移除时，会调用该方法。
 *
 * 默认该方法不做任何事情
 */
- (void)prepareForReuse;

/**
 * 设置标注视图选中状态
 *
 * @param selected 是否选中
 * @param animated  是否动画
 */
- (void)setSelected:(BOOL)selected animated:(BOOL)animated;

/**
 * 设置拖动状态
 *
 * 可以重写该方法自定义动画
 */
- (void)setDragState:(LKAnnotationViewDragState)dragState animated:(BOOL)animated NS_REQUIRES_SUPER;

@end

NS_ASSUME_NONNULL_END
