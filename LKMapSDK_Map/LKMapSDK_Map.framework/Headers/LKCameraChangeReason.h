#import "LKFoundation.h"

/**
 * 视角改变原因
 */
typedef NS_OPTIONS(NSUInteger, LKCameraChangeReason)
{
    /// 未知原因
    LKCameraChangeReasonNone = 0,

    /// 调用API方法
    LKCameraChangeReasonProgrammatic = 1 << 0,

    /// 重置为真北方向
    LKCameraChangeReasonResetNorth = 1 << 1,

    /// 平移地图
    LKCameraChangeReasonGesturePan = 1 << 2,

    /// 捏合地图
    LKCameraChangeReasonGesturePinch = 1 << 3,

    /// 旋转地图
    LKCameraChangeReasonGestureRotate = 1 << 4,

    /// 一根手指双击，地图放大
    LKCameraChangeReasonGestureZoomIn = 1 << 5,

    /// 两根手指单击，地图缩小
    LKCameraChangeReasonGestureZoomOut = 1 << 6,

    /// 一根手指长按上下拖拽，地图缩放
    LKCameraChangeReasonGestureOneFingerZoom = 1 << 7,

    /// 两根手指倾斜地图
    LKCameraChangeReasonGestureTilt = 1 << 8,

    /// 中途取消
    LKCameraChangeReasonTransitionCancelled = 1 << 16

};
