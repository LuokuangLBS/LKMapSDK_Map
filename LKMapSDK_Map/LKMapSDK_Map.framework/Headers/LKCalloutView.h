#import <UIKit/UIKit.h>
#import <QuartzCore/QuartzCore.h>

/// 箭头方向
typedef NS_OPTIONS(NSUInteger, LKCalloutArrowDirection) {
    
    /// 上
    LKCalloutArrowDirectionUp = 1 << 0,
    
    /// 下
    LKCalloutArrowDirectionDown = 1 << 1,
    
    /// 自动
    LKCalloutArrowDirectionAny = LKCalloutArrowDirectionUp | LKCalloutArrowDirectionDown
};

/// 弹出或消失动画类型
typedef NS_ENUM(NSInteger, LKCalloutAnimation) {
    
    /// bounce动画
    LKCalloutAnimationBounce,
    
    /// fade动画
    LKCalloutAnimationFade,
    
    /// stretch动画
    LKCalloutAnimationStretch
};

NS_ASSUME_NONNULL_BEGIN

extern NSTimeInterval const kLKCalloutViewRepositionDelayForUIScrollView;

@protocol LKCalloutViewDelegate;
@protocol LKAnnotation;
@class LKCalloutBackgroundView;

/**
 * 弹框类
 */
#if __IPHONE_OS_VERSION_MAX_ALLOWED < 100000
@interface LKCalloutView : UIView
#else
@interface LKCalloutView : UIView <CAAnimationDelegate>
#endif

/// 代理
@property (nonatomic, weak) id<LKCalloutViewDelegate> delegate;

/// 标题
@property (nonatomic, copy, nullable) NSString *title;

/// 副标题
@property (nonatomic, copy, nullable) NSString *subtitle;

/// 左侧辅助视图
@property (nonatomic, strong, nullable) UIView *leftAccessoryView;

/// 右侧辅助视图
@property (nonatomic, strong, nullable) UIView *rightAccessoryView;

/**
 * 标题视图
 *
 * @discussion UILabel、UITextField尺寸自适应内容，如果不想自适应，请使用@c UIView 作为UILabel、UITextField父视图，或者使用UILabel、UITextFiel的子类并重写@c -sizeThatFits 方法
 * @warning 设置此属性，将忽略 @c title 属性
 */
@property (nonatomic, strong, nullable) UIView *titleView;

/**
 * 副标题视图
 *
 * @discussion 同@c titleView
 * @warning 设置此属性，将忽略 @c subtitle 属性
 */
@property (nonatomic, strong, nullable) UIView *subtitleView;

/// 自定义视图。设置此属性， 将忽略title、subtitle、titleView、subtitleView属性
@property (nonatomic, retain, nullable) UIView *contentView;

/// 自定义视图偏移
@property (nonatomic, assign) UIEdgeInsets contentViewInset;


/// 箭头方向
@property (nonatomic, assign) LKCalloutArrowDirection permittedArrowDirection;

/// 当前箭头方向
@property (nonatomic, readonly) LKCalloutArrowDirection currentArrowDirection;

/// 弹框偏移
@property (nonatomic, assign) CGPoint calloutOffset;

/// 弹出动画。默认LKCalloutAnimationBounce
@property (nonatomic, assign) LKCalloutAnimation presentAnimation;

/// 消失动画。默认LKCalloutAnimationFade
@property (nonatomic, assign) LKCalloutAnimation dismissAnimation;

/// 偏移。如果被导航条等遮挡，可以这是此属性
@property (nonatomic, assign) UIEdgeInsets constrainedInsets;

/// 背景视图。默认LKCalloutMaskedBackgroundView或LKCalloutDrawnBackgroundView
@property (nonatomic, strong) LKCalloutBackgroundView *backgroundView;

/// 是否关联标注锚点
@property (nonatomic, readonly, assign, getter=isAnchoredToAnnotation) BOOL anchoredToAnnotation;

/// 是否自动消失
@property (nonatomic, readonly, assign) BOOL dismissesAutomatically;

/// 关联的标注
@property (nonatomic, strong) id <LKAnnotation> representedObject;


/**
 * 获取弹框实例
 *
 * @return 弹框实例
 */
+ (LKCalloutView *)calloutView;


- (void)presentCalloutFromRect:(CGRect)rect inView:(UIView *)view constrainedToView:(UIView *)constrainedView animated:(BOOL)animated;

- (void)presentCalloutFromRect:(CGRect)rect inView:(UIView *)view constrainedToRect:(CGRect)constrainedRect animated:(BOOL)animated;

- (void)presentCalloutFromRect:(CGRect)rect inLayer:(CALayer *)layer constrainedToLayer:(CALayer *)constrainedLayer animated:(BOOL)animated;

/**
 * 消失弹框
 *
 * @param animated 是否动画
 */
- (void)dismissCalloutAnimated:(BOOL)animated;

/// 子类重写该方法实现自定义动画
- (CAAnimation *)animationWithType:(LKCalloutAnimation)type presenting:(BOOL)presenting;

- (UIEdgeInsets)marginInsetsHintForPresentationFromRect:(CGRect)rect NS_SWIFT_NAME(marginInsetsHintForPresentation(from:));

@end

/**
 * 弹框代理方法
 */
@protocol LKCalloutViewDelegate <NSObject>

@optional

/// 弹框被点击时是否高亮。默认YES
- (BOOL)calloutViewShouldHighlight:(LKCalloutView *)calloutView;

/// 弹框被点击
- (void)calloutViewTapped:(LKCalloutView *)calloutView;

/**
 * 设置延迟时间
 *
 * @param calloutView 弹框
 * @param offset 偏移量
 * @returns 延迟时间
 */
- (NSTimeInterval)calloutView:(LKCalloutView *)calloutView delayForRepositionWithSize:(CGSize)offset;

/// 弹框将要弹出
- (void)calloutViewWillAppear:(LKCalloutView *)calloutView;

/// 弹框已经弹出
- (void)calloutViewDidAppear:(LKCalloutView *)calloutView;

/// 弹框将要消失
- (void)calloutViewWillDisappear:(LKCalloutView *)calloutView;

/// 弹框已经消失
- (void)calloutViewDidDisappear:(LKCalloutView *)calloutView;

@end


@interface LKCalloutBackgroundView : UIView
@property (nonatomic, assign) CGPoint arrowPoint;
@property (nonatomic, assign) BOOL highlighted;
@property (nonatomic, assign) CALayer *contentMask;
@property (nonatomic, assign) CGFloat anchorHeight;
@property (nonatomic, assign) CGFloat anchorMargin;
@end

@interface LKCalloutMaskedBackgroundView : LKCalloutBackgroundView

@end
NS_ASSUME_NONNULL_END

