from vmath import vec2, vec3, vec2i, vec3i, mat3x3, color32
from typing import overload
intptr = int

class Vector4:
    x: float # Vector x component (float)
    y: float # Vector y component (float)
    z: float # Vector z component (float)
    w: float # Vector w component (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, x: float, y: float, z: float, w: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Vector4': ...
    
class Matrix:
    m0: float # Matrix first row (4 components) (float)
    m4: float # Matrix first row (4 components) (float)
    m8: float # Matrix first row (4 components) (float)
    m12: float # Matrix first row (4 components) (float)
    m1: float # Matrix second row (4 components) (float)
    m5: float # Matrix second row (4 components) (float)
    m9: float # Matrix second row (4 components) (float)
    m13: float # Matrix second row (4 components) (float)
    m2: float # Matrix third row (4 components) (float)
    m6: float # Matrix third row (4 components) (float)
    m10: float # Matrix third row (4 components) (float)
    m14: float # Matrix third row (4 components) (float)
    m3: float # Matrix fourth row (4 components) (float)
    m7: float # Matrix fourth row (4 components) (float)
    m11: float # Matrix fourth row (4 components) (float)
    m15: float # Matrix fourth row (4 components) (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, m0: float, m4: float, m8: float, m12: float, m1: float, m5: float, m9: float, m13: float, m2: float, m6: float, m10: float, m14: float, m3: float, m7: float, m11: float, m15: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Matrix': ...
    
class Rectangle:
    x: float # Rectangle top-left corner position x (float)
    y: float # Rectangle top-left corner position y (float)
    width: float # Rectangle width (float)
    height: float # Rectangle height (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, x: float, y: float, width: float, height: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Rectangle': ...
    
class Image:
    data: intptr # Image raw data (void *)
    width: int # Image base width (int)
    height: int # Image base height (int)
    mipmaps: int # Mipmap levels, 1 by default (int)
    format: int # Data format (PixelFormat type) (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, data: intptr, width: int, height: int, mipmaps: int, format: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Image': ...
    
class Texture:
    id: int # OpenGL texture id (unsigned int)
    width: int # Texture base width (int)
    height: int # Texture base height (int)
    mipmaps: int # Mipmap levels, 1 by default (int)
    format: int # Data format (PixelFormat type) (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, id: int, width: int, height: int, mipmaps: int, format: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Texture': ...
    
class RenderTexture:
    id: int # OpenGL framebuffer object id (unsigned int)
    texture: Texture # Color buffer attachment texture (Texture)
    depth: Texture # Depth buffer attachment texture (Texture)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, id: int, texture: Texture, depth: Texture): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'RenderTexture': ...
    
class NPatchInfo:
    source: Rectangle # Texture source rectangle (Rectangle)
    left: int # Left border offset (int)
    top: int # Top border offset (int)
    right: int # Right border offset (int)
    bottom: int # Bottom border offset (int)
    layout: int # Layout of the n-patch: 3x3, 1x3 or 3x1 (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, source: Rectangle, left: int, top: int, right: int, bottom: int, layout: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'NPatchInfo': ...
    
class GlyphInfo:
    value: int # Character value (Unicode) (int)
    offsetX: int # Character offset X when drawing (int)
    offsetY: int # Character offset Y when drawing (int)
    advanceX: int # Character advance position X (int)
    image: Image # Character image data (Image)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, value: int, offsetX: int, offsetY: int, advanceX: int, image: Image): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'GlyphInfo': ...
    
class Font:
    baseSize: int # Base size (default chars height) (int)
    glyphCount: int # Number of glyph characters (int)
    glyphPadding: int # Padding around the glyph characters (int)
    texture: Texture2D # Texture atlas containing the glyphs (Texture2D)
    recs: intptr # Rectangles in texture for the glyphs (Rectangle *)
    glyphs: intptr # Glyphs info data (GlyphInfo *)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, baseSize: int, glyphCount: int, glyphPadding: int, texture: Texture2D, recs: intptr, glyphs: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Font': ...
    
class Camera3D:
    position: vec3 # Camera position (Vector3)
    target: vec3 # Camera target it looks-at (Vector3)
    up: vec3 # Camera up vector (rotation over its axis) (Vector3)
    fovy: float # Camera field-of-view aperture in Y (degrees) in perspective, used as near plane width in orthographic (float)
    projection: int # Camera projection: CAMERA_PERSPECTIVE or CAMERA_ORTHOGRAPHIC (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, position: vec3, target: vec3, up: vec3, fovy: float, projection: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Camera3D': ...
    
class Camera2D:
    offset: vec2 # Camera offset (displacement from target) (Vector2)
    target: vec2 # Camera target (rotation and zoom origin) (Vector2)
    rotation: float # Camera rotation in degrees (float)
    zoom: float # Camera zoom (scaling), should be 1.0f by default (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, offset: vec2, target: vec2, rotation: float, zoom: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Camera2D': ...
    
class Mesh:
    vertexCount: int # Number of vertices stored in arrays (int)
    triangleCount: int # Number of triangles stored (indexed or not) (int)
    vertices: intptr # Vertex position (XYZ - 3 components per vertex) (shader-location = 0) (float *)
    texcoords: intptr # Vertex texture coordinates (UV - 2 components per vertex) (shader-location = 1) (float *)
    texcoords2: intptr # Vertex texture second coordinates (UV - 2 components per vertex) (shader-location = 5) (float *)
    normals: intptr # Vertex normals (XYZ - 3 components per vertex) (shader-location = 2) (float *)
    tangents: intptr # Vertex tangents (XYZW - 4 components per vertex) (shader-location = 4) (float *)
    colors: intptr # Vertex colors (RGBA - 4 components per vertex) (shader-location = 3) (unsigned char *)
    indices: intptr # Vertex indices (in case vertex data comes indexed) (unsigned short *)
    animVertices: intptr # Animated vertex positions (after bones transformations) (float *)
    animNormals: intptr # Animated normals (after bones transformations) (float *)
    boneIds: intptr # Vertex bone ids, max 255 bone ids, up to 4 bones influence by vertex (skinning) (shader-location = 6) (unsigned char *)
    boneWeights: intptr # Vertex bone weight, up to 4 bones influence by vertex (skinning) (shader-location = 7) (float *)
    boneMatrices: intptr # Bones animated transformation matrices (Matrix *)
    boneCount: int # Number of bones (int)
    vaoId: int # OpenGL Vertex Array Object id (unsigned int)
    vboId: intptr # OpenGL Vertex Buffer Objects id (default vertex data) (unsigned int *)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, vertexCount: int, triangleCount: int, vertices: intptr, texcoords: intptr, texcoords2: intptr, normals: intptr, tangents: intptr, colors: intptr, indices: intptr, animVertices: intptr, animNormals: intptr, boneIds: intptr, boneWeights: intptr, boneMatrices: intptr, boneCount: int, vaoId: int, vboId: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Mesh': ...
    
class Shader:
    id: int # Shader program id (unsigned int)
    locs: intptr # Shader locations array (RL_MAX_SHADER_LOCATIONS) (int *)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, id: int, locs: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Shader': ...
    
class MaterialMap:
    texture: Texture2D # Material map texture (Texture2D)
    color: color32 # Material map color (Color)
    value: float # Material map value (float)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, texture: Texture2D, color: color32, value: float): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'MaterialMap': ...
    
class Material:
    shader: Shader # Material shader (Shader)
    maps: intptr # Material maps array (MAX_MATERIAL_MAPS) (MaterialMap *)
    params: intptr # Material generic parameters (if required) (float[4])
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, shader: Shader, maps: intptr, params: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Material': ...
    
class Transform:
    translation: vec3 # Translation (Vector3)
    rotation: Quaternion # Rotation (Quaternion)
    scale: vec3 # Scale (Vector3)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, translation: vec3, rotation: Quaternion, scale: vec3): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Transform': ...
    
class BoneInfo:
    name: intptr # Bone name (char[32])
    parent: int # Bone parent (int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, name: intptr, parent: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'BoneInfo': ...
    
class Model:
    transform: Matrix # Local transform matrix (Matrix)
    meshCount: int # Number of meshes (int)
    materialCount: int # Number of materials (int)
    meshes: intptr # Meshes array (Mesh *)
    materials: intptr # Materials array (Material *)
    meshMaterial: intptr # Mesh material number (int *)
    boneCount: int # Number of bones (int)
    bones: intptr # Bones information (skeleton) (BoneInfo *)
    bindPose: intptr # Bones base transformation (pose) (Transform *)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, transform: Matrix, meshCount: int, materialCount: int, meshes: intptr, materials: intptr, meshMaterial: intptr, boneCount: int, bones: intptr, bindPose: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Model': ...
    
class ModelAnimation:
    boneCount: int # Number of bones (int)
    frameCount: int # Number of animation frames (int)
    bones: intptr # Bones information (skeleton) (BoneInfo *)
    framePoses: intptr # Poses array by frame (Transform **)
    name: intptr # Animation name (char[32])
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, boneCount: int, frameCount: int, bones: intptr, framePoses: intptr, name: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'ModelAnimation': ...
    
class Ray:
    position: vec3 # Ray position (origin) (Vector3)
    direction: vec3 # Ray direction (normalized) (Vector3)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, position: vec3, direction: vec3): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Ray': ...
    
class RayCollision:
    hit: bool # Did the ray hit something? (bool)
    distance: float # Distance to the nearest hit (float)
    point: vec3 # Point of the nearest hit (Vector3)
    normal: vec3 # Surface normal of hit (Vector3)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, hit: bool, distance: float, point: vec3, normal: vec3): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'RayCollision': ...
    
class BoundingBox:
    min: vec3 # Minimum vertex box-corner (Vector3)
    max: vec3 # Maximum vertex box-corner (Vector3)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, min: vec3, max: vec3): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'BoundingBox': ...
    
class Wave:
    frameCount: int # Total number of frames (considering channels) (unsigned int)
    sampleRate: int # Frequency (samples per second) (unsigned int)
    sampleSize: int # Bit depth (bits per sample): 8, 16, 32 (24 not supported) (unsigned int)
    channels: int # Number of channels (1-mono, 2-stereo, ...) (unsigned int)
    data: intptr # Buffer data pointer (void *)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, frameCount: int, sampleRate: int, sampleSize: int, channels: int, data: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Wave': ...
    
class AudioStream:
    buffer: intptr # Pointer to internal data used by the audio system (rAudioBuffer *)
    processor: intptr # Pointer to internal data processor, useful for audio effects (rAudioProcessor *)
    sampleRate: int # Frequency (samples per second) (unsigned int)
    sampleSize: int # Bit depth (bits per sample): 8, 16, 32 (24 not supported) (unsigned int)
    channels: int # Number of channels (1-mono, 2-stereo, ...) (unsigned int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, buffer: intptr, processor: intptr, sampleRate: int, sampleSize: int, channels: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'AudioStream': ...
    
class Sound:
    stream: AudioStream # Audio stream (AudioStream)
    frameCount: int # Total number of frames (considering channels) (unsigned int)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, stream: AudioStream, frameCount: int): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Sound': ...
    
class Music:
    stream: AudioStream # Audio stream (AudioStream)
    frameCount: int # Total number of frames (considering channels) (unsigned int)
    looping: bool # Music looping enable (bool)
    ctxType: int # Type of music context (audio filetype) (int)
    ctxData: intptr # Audio context data, depends on type (void *)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, stream: AudioStream, frameCount: int, looping: bool, ctxType: int, ctxData: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'Music': ...
    
class VrDeviceInfo:
    hResolution: int # Horizontal resolution in pixels (int)
    vResolution: int # Vertical resolution in pixels (int)
    hScreenSize: float # Horizontal size in meters (float)
    vScreenSize: float # Vertical size in meters (float)
    eyeToScreenDistance: float # Distance between eye and display in meters (float)
    lensSeparationDistance: float # Lens separation distance in meters (float)
    interpupillaryDistance: float # IPD (distance between pupils) in meters (float)
    lensDistortionValues: intptr # Lens distortion constant parameters (float[4])
    chromaAbCorrection: intptr # Chromatic aberration correction parameters (float[4])
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, hResolution: int, vResolution: int, hScreenSize: float, vScreenSize: float, eyeToScreenDistance: float, lensSeparationDistance: float, interpupillaryDistance: float, lensDistortionValues: intptr, chromaAbCorrection: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'VrDeviceInfo': ...
    
class VrStereoConfig:
    projection: intptr # VR projection matrices (per eye) (Matrix[2])
    viewOffset: intptr # VR view offset matrices (per eye) (Matrix[2])
    leftLensCenter: intptr # VR left lens center (float[2])
    rightLensCenter: intptr # VR right lens center (float[2])
    leftScreenCenter: intptr # VR left screen center (float[2])
    rightScreenCenter: intptr # VR right screen center (float[2])
    scale: intptr # VR distortion scale (float[2])
    scaleIn: intptr # VR distortion scale in (float[2])
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, projection: intptr, viewOffset: intptr, leftLensCenter: intptr, rightLensCenter: intptr, leftScreenCenter: intptr, rightScreenCenter: intptr, scale: intptr, scaleIn: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'VrStereoConfig': ...
    
class FilePathList:
    capacity: int # Filepaths max entries (unsigned int)
    count: int # Filepaths entries count (unsigned int)
    paths: intptr # Filepaths entries (char **)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, capacity: int, count: int, paths: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'FilePathList': ...
    
class AutomationEvent:
    frame: int # Event frame (unsigned int)
    type: int # Event type (AutomationEventType) (unsigned int)
    params: intptr # Event parameters (if required) (int[4])
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, frame: int, type: int, params: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'AutomationEvent': ...
    
class AutomationEventList:
    capacity: int # Events max entries (MAX_AUTOMATION_EVENTS) (unsigned int)
    count: int # Events entries count (unsigned int)
    events: intptr # Events entries (AutomationEvent *)
    
    @overload
    def __init__(self): ...
    @overload
    def __init__(self, capacity: int, count: int, events: intptr): ...
    def __address__(self) -> int: ...
    def copy(self) -> 'AutomationEventList': ...
    
def InitWindow(width: int, height: int, title: str) -> None:
    """Wraps `void InitWindow(int width, int height, const char * title)`

    Initialize window and OpenGL context"""

def CloseWindow() -> None:
    """Wraps `void CloseWindow()`

    Close window and unload OpenGL context"""

def WindowShouldClose() -> bool:
    """Wraps `bool WindowShouldClose()`

    Check if application should close (KEY_ESCAPE pressed or windows close icon clicked)"""

def IsWindowReady() -> bool:
    """Wraps `bool IsWindowReady()`

    Check if window has been initialized successfully"""

def IsWindowFullscreen() -> bool:
    """Wraps `bool IsWindowFullscreen()`

    Check if window is currently fullscreen"""

def IsWindowHidden() -> bool:
    """Wraps `bool IsWindowHidden()`

    Check if window is currently hidden"""

def IsWindowMinimized() -> bool:
    """Wraps `bool IsWindowMinimized()`

    Check if window is currently minimized"""

def IsWindowMaximized() -> bool:
    """Wraps `bool IsWindowMaximized()`

    Check if window is currently maximized"""

def IsWindowFocused() -> bool:
    """Wraps `bool IsWindowFocused()`

    Check if window is currently focused"""

def IsWindowResized() -> bool:
    """Wraps `bool IsWindowResized()`

    Check if window has been resized last frame"""

def IsWindowState(flag: int) -> bool:
    """Wraps `bool IsWindowState(unsigned int flag)`

    Check if one specific window flag is enabled"""

def SetWindowState(flags: int) -> None:
    """Wraps `void SetWindowState(unsigned int flags)`

    Set window configuration state using flags"""

def ClearWindowState(flags: int) -> None:
    """Wraps `void ClearWindowState(unsigned int flags)`

    Clear window configuration state flags"""

def ToggleFullscreen() -> None:
    """Wraps `void ToggleFullscreen()`

    Toggle window state: fullscreen/windowed, resizes monitor to match window resolution"""

def ToggleBorderlessWindowed() -> None:
    """Wraps `void ToggleBorderlessWindowed()`

    Toggle window state: borderless windowed, resizes window to match monitor resolution"""

def MaximizeWindow() -> None:
    """Wraps `void MaximizeWindow()`

    Set window state: maximized, if resizable"""

def MinimizeWindow() -> None:
    """Wraps `void MinimizeWindow()`

    Set window state: minimized, if resizable"""

def RestoreWindow() -> None:
    """Wraps `void RestoreWindow()`

    Set window state: not minimized/maximized"""

def SetWindowIcon(image: Image) -> None:
    """Wraps `void SetWindowIcon(Image image)`

    Set icon for window (single image, RGBA 32bit)"""

def SetWindowIcons(images: intptr, count: int) -> None:
    """Wraps `void SetWindowIcons(Image * images, int count)`

    Set icon for window (multiple images, RGBA 32bit)"""

def SetWindowTitle(title: str) -> None:
    """Wraps `void SetWindowTitle(const char * title)`

    Set title for window"""

def SetWindowPosition(x: int, y: int) -> None:
    """Wraps `void SetWindowPosition(int x, int y)`

    Set window position on screen"""

def SetWindowMonitor(monitor: int) -> None:
    """Wraps `void SetWindowMonitor(int monitor)`

    Set monitor for the current window"""

def SetWindowMinSize(width: int, height: int) -> None:
    """Wraps `void SetWindowMinSize(int width, int height)`

    Set window minimum dimensions (for FLAG_WINDOW_RESIZABLE)"""

def SetWindowMaxSize(width: int, height: int) -> None:
    """Wraps `void SetWindowMaxSize(int width, int height)`

    Set window maximum dimensions (for FLAG_WINDOW_RESIZABLE)"""

def SetWindowSize(width: int, height: int) -> None:
    """Wraps `void SetWindowSize(int width, int height)`

    Set window dimensions"""

def SetWindowOpacity(opacity: float) -> None:
    """Wraps `void SetWindowOpacity(float opacity)`

    Set window opacity [0.0f..1.0f]"""

def SetWindowFocused() -> None:
    """Wraps `void SetWindowFocused()`

    Set window focused"""

def GetWindowHandle() -> intptr:
    """Wraps `void * GetWindowHandle()`

    Get native window handle"""

def GetScreenWidth() -> int:
    """Wraps `int GetScreenWidth()`

    Get current screen width"""

def GetScreenHeight() -> int:
    """Wraps `int GetScreenHeight()`

    Get current screen height"""

def GetRenderWidth() -> int:
    """Wraps `int GetRenderWidth()`

    Get current render width (it considers HiDPI)"""

def GetRenderHeight() -> int:
    """Wraps `int GetRenderHeight()`

    Get current render height (it considers HiDPI)"""

def GetMonitorCount() -> int:
    """Wraps `int GetMonitorCount()`

    Get number of connected monitors"""

def GetCurrentMonitor() -> int:
    """Wraps `int GetCurrentMonitor()`

    Get current monitor where window is placed"""

def GetMonitorPosition(monitor: int) -> vec2:
    """Wraps `Vector2 GetMonitorPosition(int monitor)`

    Get specified monitor position"""

def GetMonitorWidth(monitor: int) -> int:
    """Wraps `int GetMonitorWidth(int monitor)`

    Get specified monitor width (current video mode used by monitor)"""

def GetMonitorHeight(monitor: int) -> int:
    """Wraps `int GetMonitorHeight(int monitor)`

    Get specified monitor height (current video mode used by monitor)"""

def GetMonitorPhysicalWidth(monitor: int) -> int:
    """Wraps `int GetMonitorPhysicalWidth(int monitor)`

    Get specified monitor physical width in millimetres"""

def GetMonitorPhysicalHeight(monitor: int) -> int:
    """Wraps `int GetMonitorPhysicalHeight(int monitor)`

    Get specified monitor physical height in millimetres"""

def GetMonitorRefreshRate(monitor: int) -> int:
    """Wraps `int GetMonitorRefreshRate(int monitor)`

    Get specified monitor refresh rate"""

def GetWindowPosition() -> vec2:
    """Wraps `Vector2 GetWindowPosition()`

    Get window position XY on monitor"""

def GetWindowScaleDPI() -> vec2:
    """Wraps `Vector2 GetWindowScaleDPI()`

    Get window scale DPI factor"""

def GetMonitorName(monitor: int) -> str:
    """Wraps `const char * GetMonitorName(int monitor)`

    Get the human-readable, UTF-8 encoded name of the specified monitor"""

def SetClipboardText(text: str) -> None:
    """Wraps `void SetClipboardText(const char * text)`

    Set clipboard text content"""

def GetClipboardText() -> str:
    """Wraps `const char * GetClipboardText()`

    Get clipboard text content"""

def GetClipboardImage() -> Image:
    """Wraps `Image GetClipboardImage()`

    Get clipboard image content"""

def EnableEventWaiting() -> None:
    """Wraps `void EnableEventWaiting()`

    Enable waiting for events on EndDrawing(), no automatic event polling"""

def DisableEventWaiting() -> None:
    """Wraps `void DisableEventWaiting()`

    Disable waiting for events on EndDrawing(), automatic events polling"""

def ShowCursor() -> None:
    """Wraps `void ShowCursor()`

    Shows cursor"""

def HideCursor() -> None:
    """Wraps `void HideCursor()`

    Hides cursor"""

def IsCursorHidden() -> bool:
    """Wraps `bool IsCursorHidden()`

    Check if cursor is not visible"""

def EnableCursor() -> None:
    """Wraps `void EnableCursor()`

    Enables cursor (unlock cursor)"""

def DisableCursor() -> None:
    """Wraps `void DisableCursor()`

    Disables cursor (lock cursor)"""

def IsCursorOnScreen() -> bool:
    """Wraps `bool IsCursorOnScreen()`

    Check if cursor is on the screen"""

def ClearBackground(color: color32) -> None:
    """Wraps `void ClearBackground(Color color)`

    Set background color (framebuffer clear color)"""

def BeginDrawing() -> None:
    """Wraps `void BeginDrawing()`

    Setup canvas (framebuffer) to start drawing"""

def EndDrawing() -> None:
    """Wraps `void EndDrawing()`

    End canvas drawing and swap buffers (double buffering)"""

def BeginMode2D(camera: Camera2D) -> None:
    """Wraps `void BeginMode2D(Camera2D camera)`

    Begin 2D mode with custom camera (2D)"""

def EndMode2D() -> None:
    """Wraps `void EndMode2D()`

    Ends 2D mode with custom camera"""

def BeginMode3D(camera: Camera3D) -> None:
    """Wraps `void BeginMode3D(Camera3D camera)`

    Begin 3D mode with custom camera (3D)"""

def EndMode3D() -> None:
    """Wraps `void EndMode3D()`

    Ends 3D mode and returns to default 2D orthographic mode"""

def BeginTextureMode(target: RenderTexture2D) -> None:
    """Wraps `void BeginTextureMode(RenderTexture2D target)`

    Begin drawing to render texture"""

def EndTextureMode() -> None:
    """Wraps `void EndTextureMode()`

    Ends drawing to render texture"""

def BeginShaderMode(shader: Shader) -> None:
    """Wraps `void BeginShaderMode(Shader shader)`

    Begin custom shader drawing"""

def EndShaderMode() -> None:
    """Wraps `void EndShaderMode()`

    End custom shader drawing (use default shader)"""

def BeginBlendMode(mode: int) -> None:
    """Wraps `void BeginBlendMode(int mode)`

    Begin blending mode (alpha, additive, multiplied, subtract, custom)"""

def EndBlendMode() -> None:
    """Wraps `void EndBlendMode()`

    End blending mode (reset to default: alpha blending)"""

def BeginScissorMode(x: int, y: int, width: int, height: int) -> None:
    """Wraps `void BeginScissorMode(int x, int y, int width, int height)`

    Begin scissor mode (define screen area for following drawing)"""

def EndScissorMode() -> None:
    """Wraps `void EndScissorMode()`

    End scissor mode"""

def BeginVrStereoMode(config: VrStereoConfig) -> None:
    """Wraps `void BeginVrStereoMode(VrStereoConfig config)`

    Begin stereo rendering (requires VR simulator)"""

def EndVrStereoMode() -> None:
    """Wraps `void EndVrStereoMode()`

    End stereo rendering (requires VR simulator)"""

def LoadVrStereoConfig(device: VrDeviceInfo) -> VrStereoConfig:
    """Wraps `VrStereoConfig LoadVrStereoConfig(VrDeviceInfo device)`

    Load VR stereo config for VR simulator device parameters"""

def UnloadVrStereoConfig(config: VrStereoConfig) -> None:
    """Wraps `void UnloadVrStereoConfig(VrStereoConfig config)`

    Unload VR stereo config"""

def LoadShader(vsFileName: str, fsFileName: str) -> Shader:
    """Wraps `Shader LoadShader(const char * vsFileName, const char * fsFileName)`

    Load shader from files and bind default locations"""

def LoadShaderFromMemory(vsCode: str, fsCode: str) -> Shader:
    """Wraps `Shader LoadShaderFromMemory(const char * vsCode, const char * fsCode)`

    Load shader from code strings and bind default locations"""

def IsShaderValid(shader: Shader) -> bool:
    """Wraps `bool IsShaderValid(Shader shader)`

    Check if a shader is valid (loaded on GPU)"""

def GetShaderLocation(shader: Shader, uniformName: str) -> int:
    """Wraps `int GetShaderLocation(Shader shader, const char * uniformName)`

    Get shader uniform location"""

def GetShaderLocationAttrib(shader: Shader, attribName: str) -> int:
    """Wraps `int GetShaderLocationAttrib(Shader shader, const char * attribName)`

    Get shader attribute location"""

def SetShaderValue(shader: Shader, locIndex: int, value: intptr, uniformType: int) -> None:
    """Wraps `void SetShaderValue(Shader shader, int locIndex, const void * value, int uniformType)`

    Set shader uniform value"""

def SetShaderValueV(shader: Shader, locIndex: int, value: intptr, uniformType: int, count: int) -> None:
    """Wraps `void SetShaderValueV(Shader shader, int locIndex, const void * value, int uniformType, int count)`

    Set shader uniform value vector"""

def SetShaderValueMatrix(shader: Shader, locIndex: int, mat: Matrix) -> None:
    """Wraps `void SetShaderValueMatrix(Shader shader, int locIndex, Matrix mat)`

    Set shader uniform value (matrix 4x4)"""

def SetShaderValueTexture(shader: Shader, locIndex: int, texture: Texture2D) -> None:
    """Wraps `void SetShaderValueTexture(Shader shader, int locIndex, Texture2D texture)`

    Set shader uniform value for texture (sampler2d)"""

def UnloadShader(shader: Shader) -> None:
    """Wraps `void UnloadShader(Shader shader)`

    Unload shader from GPU memory (VRAM)"""

def GetScreenToWorldRay(position: vec2, camera: Camera) -> Ray:
    """Wraps `Ray GetScreenToWorldRay(Vector2 position, Camera camera)`

    Get a ray trace from screen position (i.e mouse)"""

def GetScreenToWorldRayEx(position: vec2, camera: Camera, width: int, height: int) -> Ray:
    """Wraps `Ray GetScreenToWorldRayEx(Vector2 position, Camera camera, int width, int height)`

    Get a ray trace from screen position (i.e mouse) in a viewport"""

def GetWorldToScreen(position: vec3, camera: Camera) -> vec2:
    """Wraps `Vector2 GetWorldToScreen(Vector3 position, Camera camera)`

    Get the screen space position for a 3d world space position"""

def GetWorldToScreenEx(position: vec3, camera: Camera, width: int, height: int) -> vec2:
    """Wraps `Vector2 GetWorldToScreenEx(Vector3 position, Camera camera, int width, int height)`

    Get size position for a 3d world space position"""

def GetWorldToScreen2D(position: vec2, camera: Camera2D) -> vec2:
    """Wraps `Vector2 GetWorldToScreen2D(Vector2 position, Camera2D camera)`

    Get the screen space position for a 2d camera world space position"""

def GetScreenToWorld2D(position: vec2, camera: Camera2D) -> vec2:
    """Wraps `Vector2 GetScreenToWorld2D(Vector2 position, Camera2D camera)`

    Get the world space position for a 2d camera screen space position"""

def GetCameraMatrix(camera: Camera) -> Matrix:
    """Wraps `Matrix GetCameraMatrix(Camera camera)`

    Get camera transform matrix (view matrix)"""

def GetCameraMatrix2D(camera: Camera2D) -> Matrix:
    """Wraps `Matrix GetCameraMatrix2D(Camera2D camera)`

    Get camera 2d transform matrix"""

def SetTargetFPS(fps: int) -> None:
    """Wraps `void SetTargetFPS(int fps)`

    Set target FPS (maximum)"""

def GetFrameTime() -> float:
    """Wraps `float GetFrameTime()`

    Get time in seconds for last frame drawn (delta time)"""

def GetTime() -> float:
    """Wraps `double GetTime()`

    Get elapsed time in seconds since InitWindow()"""

def GetFPS() -> int:
    """Wraps `int GetFPS()`

    Get current FPS"""

def SwapScreenBuffer() -> None:
    """Wraps `void SwapScreenBuffer()`

    Swap back buffer with front buffer (screen drawing)"""

def PollInputEvents() -> None:
    """Wraps `void PollInputEvents()`

    Register all input events"""

def WaitTime(seconds: float) -> None:
    """Wraps `void WaitTime(double seconds)`

    Wait for some time (halt program execution)"""

def SetRandomSeed(seed: int) -> None:
    """Wraps `void SetRandomSeed(unsigned int seed)`

    Set the seed for the random number generator"""

def GetRandomValue(min: int, max: int) -> int:
    """Wraps `int GetRandomValue(int min, int max)`

    Get a random value between min and max (both included)"""

def LoadRandomSequence(count: int, min: int, max: int) -> intptr:
    """Wraps `int * LoadRandomSequence(unsigned int count, int min, int max)`

    Load random values sequence, no values repeated"""

def UnloadRandomSequence(sequence: intptr) -> None:
    """Wraps `void UnloadRandomSequence(int * sequence)`

    Unload random values sequence"""

def TakeScreenshot(fileName: str) -> None:
    """Wraps `void TakeScreenshot(const char * fileName)`

    Takes a screenshot of current screen (filename extension defines format)"""

def SetConfigFlags(flags: int) -> None:
    """Wraps `void SetConfigFlags(unsigned int flags)`

    Setup init configuration flags (view FLAGS)"""

def OpenURL(url: str) -> None:
    """Wraps `void OpenURL(const char * url)`

    Open URL with default system browser (if available)"""

def SetTraceLogLevel(logLevel: int) -> None:
    """Wraps `void SetTraceLogLevel(int logLevel)`

    Set the current threshold (minimum) log level"""

def MemAlloc(size: int) -> intptr:
    """Wraps `void * MemAlloc(unsigned int size)`

    Internal memory allocator"""

def MemRealloc(ptr: intptr, size: int) -> intptr:
    """Wraps `void * MemRealloc(void * ptr, unsigned int size)`

    Internal memory reallocator"""

def MemFree(ptr: intptr) -> None:
    """Wraps `void MemFree(void * ptr)`

    Internal memory free"""

def LoadFileData(fileName: str, dataSize: intptr) -> intptr:
    """Wraps `unsigned char * LoadFileData(const char * fileName, int * dataSize)`

    Load file data as byte array (read)"""

def UnloadFileData(data: intptr) -> None:
    """Wraps `void UnloadFileData(unsigned char * data)`

    Unload file data allocated by LoadFileData()"""

def SaveFileData(fileName: str, data: intptr, dataSize: int) -> bool:
    """Wraps `bool SaveFileData(const char * fileName, void * data, int dataSize)`

    Save data to file from byte array (write), returns true on success"""

def ExportDataAsCode(data: intptr, dataSize: int, fileName: str) -> bool:
    """Wraps `bool ExportDataAsCode(const unsigned char * data, int dataSize, const char * fileName)`

    Export data to code (.h), returns true on success"""

def LoadFileText(fileName: str) -> intptr:
    """Wraps `char * LoadFileText(const char * fileName)`

    Load text data from file (read), returns a '\0' terminated string"""

def UnloadFileText(text: intptr) -> None:
    """Wraps `void UnloadFileText(char * text)`

    Unload file text data allocated by LoadFileText()"""

def SaveFileText(fileName: str, text: intptr) -> bool:
    """Wraps `bool SaveFileText(const char * fileName, char * text)`

    Save text data to file (write), string must be '\0' terminated, returns true on success"""

def FileExists(fileName: str) -> bool:
    """Wraps `bool FileExists(const char * fileName)`

    Check if file exists"""

def DirectoryExists(dirPath: str) -> bool:
    """Wraps `bool DirectoryExists(const char * dirPath)`

    Check if a directory path exists"""

def IsFileExtension(fileName: str, ext: str) -> bool:
    """Wraps `bool IsFileExtension(const char * fileName, const char * ext)`

    Check file extension (including point: .png, .wav)"""

def GetFileLength(fileName: str) -> int:
    """Wraps `int GetFileLength(const char * fileName)`

    Get file length in bytes (NOTE: GetFileSize() conflicts with windows.h)"""

def GetFileExtension(fileName: str) -> str:
    """Wraps `const char * GetFileExtension(const char * fileName)`

    Get pointer to extension for a filename string (includes dot: '.png')"""

def GetFileName(filePath: str) -> str:
    """Wraps `const char * GetFileName(const char * filePath)`

    Get pointer to filename for a path string"""

def GetFileNameWithoutExt(filePath: str) -> str:
    """Wraps `const char * GetFileNameWithoutExt(const char * filePath)`

    Get filename string without extension (uses static string)"""

def GetDirectoryPath(filePath: str) -> str:
    """Wraps `const char * GetDirectoryPath(const char * filePath)`

    Get full path for a given fileName with path (uses static string)"""

def GetPrevDirectoryPath(dirPath: str) -> str:
    """Wraps `const char * GetPrevDirectoryPath(const char * dirPath)`

    Get previous directory path for a given path (uses static string)"""

def GetWorkingDirectory() -> str:
    """Wraps `const char * GetWorkingDirectory()`

    Get current working directory (uses static string)"""

def GetApplicationDirectory() -> str:
    """Wraps `const char * GetApplicationDirectory()`

    Get the directory of the running application (uses static string)"""

def MakeDirectory(dirPath: str) -> int:
    """Wraps `int MakeDirectory(const char * dirPath)`

    Create directories (including full path requested), returns 0 on success"""

def ChangeDirectory(dir: str) -> bool:
    """Wraps `bool ChangeDirectory(const char * dir)`

    Change working directory, return true on success"""

def IsPathFile(path: str) -> bool:
    """Wraps `bool IsPathFile(const char * path)`

    Check if a given path is a file or a directory"""

def IsFileNameValid(fileName: str) -> bool:
    """Wraps `bool IsFileNameValid(const char * fileName)`

    Check if fileName is valid for the platform/OS"""

def LoadDirectoryFiles(dirPath: str) -> FilePathList:
    """Wraps `FilePathList LoadDirectoryFiles(const char * dirPath)`

    Load directory filepaths"""

def LoadDirectoryFilesEx(basePath: str, filter: str, scanSubdirs: bool) -> FilePathList:
    """Wraps `FilePathList LoadDirectoryFilesEx(const char * basePath, const char * filter, bool scanSubdirs)`

    Load directory filepaths with extension filtering and recursive directory scan. Use 'DIR' in the filter string to include directories in the result"""

def UnloadDirectoryFiles(files: FilePathList) -> None:
    """Wraps `void UnloadDirectoryFiles(FilePathList files)`

    Unload filepaths"""

def IsFileDropped() -> bool:
    """Wraps `bool IsFileDropped()`

    Check if a file has been dropped into window"""

def LoadDroppedFiles() -> FilePathList:
    """Wraps `FilePathList LoadDroppedFiles()`

    Load dropped filepaths"""

def UnloadDroppedFiles(files: FilePathList) -> None:
    """Wraps `void UnloadDroppedFiles(FilePathList files)`

    Unload dropped filepaths"""

def GetFileModTime(fileName: str) -> int:
    """Wraps `long GetFileModTime(const char * fileName)`

    Get file modification time (last write time)"""

def CompressData(data: intptr, dataSize: int, compDataSize: intptr) -> intptr:
    """Wraps `unsigned char * CompressData(const unsigned char * data, int dataSize, int * compDataSize)`

    Compress data (DEFLATE algorithm), memory must be MemFree()"""

def DecompressData(compData: intptr, compDataSize: int, dataSize: intptr) -> intptr:
    """Wraps `unsigned char * DecompressData(const unsigned char * compData, int compDataSize, int * dataSize)`

    Decompress data (DEFLATE algorithm), memory must be MemFree()"""

def EncodeDataBase64(data: intptr, dataSize: int, outputSize: intptr) -> intptr:
    """Wraps `char * EncodeDataBase64(const unsigned char * data, int dataSize, int * outputSize)`

    Encode data to Base64 string, memory must be MemFree()"""

def DecodeDataBase64(data: intptr, outputSize: intptr) -> intptr:
    """Wraps `unsigned char * DecodeDataBase64(const unsigned char * data, int * outputSize)`

    Decode Base64 string data, memory must be MemFree()"""

def ComputeCRC32(data: intptr, dataSize: int) -> int:
    """Wraps `unsigned int ComputeCRC32(unsigned char * data, int dataSize)`

    Compute CRC32 hash code"""

def ComputeMD5(data: intptr, dataSize: int) -> intptr:
    """Wraps `unsigned int * ComputeMD5(unsigned char * data, int dataSize)`

    Compute MD5 hash code, returns static int[4] (16 bytes)"""

def ComputeSHA1(data: intptr, dataSize: int) -> intptr:
    """Wraps `unsigned int * ComputeSHA1(unsigned char * data, int dataSize)`

    Compute SHA1 hash code, returns static int[5] (20 bytes)"""

def LoadAutomationEventList(fileName: str) -> AutomationEventList:
    """Wraps `AutomationEventList LoadAutomationEventList(const char * fileName)`

    Load automation events list from file, NULL for empty list, capacity = MAX_AUTOMATION_EVENTS"""

def UnloadAutomationEventList(list: AutomationEventList) -> None:
    """Wraps `void UnloadAutomationEventList(AutomationEventList list)`

    Unload automation events list from file"""

def ExportAutomationEventList(list: AutomationEventList, fileName: str) -> bool:
    """Wraps `bool ExportAutomationEventList(AutomationEventList list, const char * fileName)`

    Export automation events list as text file"""

def SetAutomationEventList(list: intptr) -> None:
    """Wraps `void SetAutomationEventList(AutomationEventList * list)`

    Set automation event list to record to"""

def SetAutomationEventBaseFrame(frame: int) -> None:
    """Wraps `void SetAutomationEventBaseFrame(int frame)`

    Set automation event internal base frame to start recording"""

def StartAutomationEventRecording() -> None:
    """Wraps `void StartAutomationEventRecording()`

    Start recording automation events (AutomationEventList must be set)"""

def StopAutomationEventRecording() -> None:
    """Wraps `void StopAutomationEventRecording()`

    Stop recording automation events"""

def PlayAutomationEvent(event: AutomationEvent) -> None:
    """Wraps `void PlayAutomationEvent(AutomationEvent event)`

    Play a recorded automation event"""

def IsKeyPressed(key: int) -> bool:
    """Wraps `bool IsKeyPressed(int key)`

    Check if a key has been pressed once"""

def IsKeyPressedRepeat(key: int) -> bool:
    """Wraps `bool IsKeyPressedRepeat(int key)`

    Check if a key has been pressed again"""

def IsKeyDown(key: int) -> bool:
    """Wraps `bool IsKeyDown(int key)`

    Check if a key is being pressed"""

def IsKeyReleased(key: int) -> bool:
    """Wraps `bool IsKeyReleased(int key)`

    Check if a key has been released once"""

def IsKeyUp(key: int) -> bool:
    """Wraps `bool IsKeyUp(int key)`

    Check if a key is NOT being pressed"""

def GetKeyPressed() -> int:
    """Wraps `int GetKeyPressed()`

    Get key pressed (keycode), call it multiple times for keys queued, returns 0 when the queue is empty"""

def GetCharPressed() -> int:
    """Wraps `int GetCharPressed()`

    Get char pressed (unicode), call it multiple times for chars queued, returns 0 when the queue is empty"""

def SetExitKey(key: int) -> None:
    """Wraps `void SetExitKey(int key)`

    Set a custom key to exit program (default is ESC)"""

def IsGamepadAvailable(gamepad: int) -> bool:
    """Wraps `bool IsGamepadAvailable(int gamepad)`

    Check if a gamepad is available"""

def GetGamepadName(gamepad: int) -> str:
    """Wraps `const char * GetGamepadName(int gamepad)`

    Get gamepad internal name id"""

def IsGamepadButtonPressed(gamepad: int, button: int) -> bool:
    """Wraps `bool IsGamepadButtonPressed(int gamepad, int button)`

    Check if a gamepad button has been pressed once"""

def IsGamepadButtonDown(gamepad: int, button: int) -> bool:
    """Wraps `bool IsGamepadButtonDown(int gamepad, int button)`

    Check if a gamepad button is being pressed"""

def IsGamepadButtonReleased(gamepad: int, button: int) -> bool:
    """Wraps `bool IsGamepadButtonReleased(int gamepad, int button)`

    Check if a gamepad button has been released once"""

def IsGamepadButtonUp(gamepad: int, button: int) -> bool:
    """Wraps `bool IsGamepadButtonUp(int gamepad, int button)`

    Check if a gamepad button is NOT being pressed"""

def GetGamepadButtonPressed() -> int:
    """Wraps `int GetGamepadButtonPressed()`

    Get the last gamepad button pressed"""

def GetGamepadAxisCount(gamepad: int) -> int:
    """Wraps `int GetGamepadAxisCount(int gamepad)`

    Get gamepad axis count for a gamepad"""

def GetGamepadAxisMovement(gamepad: int, axis: int) -> float:
    """Wraps `float GetGamepadAxisMovement(int gamepad, int axis)`

    Get axis movement value for a gamepad axis"""

def SetGamepadMappings(mappings: str) -> int:
    """Wraps `int SetGamepadMappings(const char * mappings)`

    Set internal gamepad mappings (SDL_GameControllerDB)"""

def SetGamepadVibration(gamepad: int, leftMotor: float, rightMotor: float, duration: float) -> None:
    """Wraps `void SetGamepadVibration(int gamepad, float leftMotor, float rightMotor, float duration)`

    Set gamepad vibration for both motors (duration in seconds)"""

def IsMouseButtonPressed(button: int) -> bool:
    """Wraps `bool IsMouseButtonPressed(int button)`

    Check if a mouse button has been pressed once"""

def IsMouseButtonDown(button: int) -> bool:
    """Wraps `bool IsMouseButtonDown(int button)`

    Check if a mouse button is being pressed"""

def IsMouseButtonReleased(button: int) -> bool:
    """Wraps `bool IsMouseButtonReleased(int button)`

    Check if a mouse button has been released once"""

def IsMouseButtonUp(button: int) -> bool:
    """Wraps `bool IsMouseButtonUp(int button)`

    Check if a mouse button is NOT being pressed"""

def GetMouseX() -> int:
    """Wraps `int GetMouseX()`

    Get mouse position X"""

def GetMouseY() -> int:
    """Wraps `int GetMouseY()`

    Get mouse position Y"""

def GetMousePosition() -> vec2:
    """Wraps `Vector2 GetMousePosition()`

    Get mouse position XY"""

def GetMouseDelta() -> vec2:
    """Wraps `Vector2 GetMouseDelta()`

    Get mouse delta between frames"""

def SetMousePosition(x: int, y: int) -> None:
    """Wraps `void SetMousePosition(int x, int y)`

    Set mouse position XY"""

def SetMouseOffset(offsetX: int, offsetY: int) -> None:
    """Wraps `void SetMouseOffset(int offsetX, int offsetY)`

    Set mouse offset"""

def SetMouseScale(scaleX: float, scaleY: float) -> None:
    """Wraps `void SetMouseScale(float scaleX, float scaleY)`

    Set mouse scaling"""

def GetMouseWheelMove() -> float:
    """Wraps `float GetMouseWheelMove()`

    Get mouse wheel movement for X or Y, whichever is larger"""

def GetMouseWheelMoveV() -> vec2:
    """Wraps `Vector2 GetMouseWheelMoveV()`

    Get mouse wheel movement for both X and Y"""

def SetMouseCursor(cursor: int) -> None:
    """Wraps `void SetMouseCursor(int cursor)`

    Set mouse cursor"""

def GetTouchX() -> int:
    """Wraps `int GetTouchX()`

    Get touch position X for touch point 0 (relative to screen size)"""

def GetTouchY() -> int:
    """Wraps `int GetTouchY()`

    Get touch position Y for touch point 0 (relative to screen size)"""

def GetTouchPosition(index: int) -> vec2:
    """Wraps `Vector2 GetTouchPosition(int index)`

    Get touch position XY for a touch point index (relative to screen size)"""

def GetTouchPointId(index: int) -> int:
    """Wraps `int GetTouchPointId(int index)`

    Get touch point identifier for given index"""

def GetTouchPointCount() -> int:
    """Wraps `int GetTouchPointCount()`

    Get number of touch points"""

def SetGesturesEnabled(flags: int) -> None:
    """Wraps `void SetGesturesEnabled(unsigned int flags)`

    Enable a set of gestures using flags"""

def IsGestureDetected(gesture: int) -> bool:
    """Wraps `bool IsGestureDetected(unsigned int gesture)`

    Check if a gesture have been detected"""

def GetGestureDetected() -> int:
    """Wraps `int GetGestureDetected()`

    Get latest detected gesture"""

def GetGestureHoldDuration() -> float:
    """Wraps `float GetGestureHoldDuration()`

    Get gesture hold time in seconds"""

def GetGestureDragVector() -> vec2:
    """Wraps `Vector2 GetGestureDragVector()`

    Get gesture drag vector"""

def GetGestureDragAngle() -> float:
    """Wraps `float GetGestureDragAngle()`

    Get gesture drag angle"""

def GetGesturePinchVector() -> vec2:
    """Wraps `Vector2 GetGesturePinchVector()`

    Get gesture pinch delta"""

def GetGesturePinchAngle() -> float:
    """Wraps `float GetGesturePinchAngle()`

    Get gesture pinch angle"""

def UpdateCamera(camera: intptr, mode: int) -> None:
    """Wraps `void UpdateCamera(Camera * camera, int mode)`

    Update camera position for selected mode"""

def UpdateCameraPro(camera: intptr, movement: vec3, rotation: vec3, zoom: float) -> None:
    """Wraps `void UpdateCameraPro(Camera * camera, Vector3 movement, Vector3 rotation, float zoom)`

    Update camera movement/rotation"""

def SetShapesTexture(texture: Texture2D, source: Rectangle) -> None:
    """Wraps `void SetShapesTexture(Texture2D texture, Rectangle source)`

    Set texture and rectangle to be used on shapes drawing"""

def GetShapesTexture() -> Texture2D:
    """Wraps `Texture2D GetShapesTexture()`

    Get texture that is used for shapes drawing"""

def GetShapesTextureRectangle() -> Rectangle:
    """Wraps `Rectangle GetShapesTextureRectangle()`

    Get texture source rectangle that is used for shapes drawing"""

def DrawPixel(posX: int, posY: int, color: color32) -> None:
    """Wraps `void DrawPixel(int posX, int posY, Color color)`

    Draw a pixel using geometry [Can be slow, use with care]"""

def DrawPixelV(position: vec2, color: color32) -> None:
    """Wraps `void DrawPixelV(Vector2 position, Color color)`

    Draw a pixel using geometry (Vector version) [Can be slow, use with care]"""

def DrawLine(startPosX: int, startPosY: int, endPosX: int, endPosY: int, color: color32) -> None:
    """Wraps `void DrawLine(int startPosX, int startPosY, int endPosX, int endPosY, Color color)`

    Draw a line"""

def DrawLineV(startPos: vec2, endPos: vec2, color: color32) -> None:
    """Wraps `void DrawLineV(Vector2 startPos, Vector2 endPos, Color color)`

    Draw a line (using gl lines)"""

def DrawLineEx(startPos: vec2, endPos: vec2, thick: float, color: color32) -> None:
    """Wraps `void DrawLineEx(Vector2 startPos, Vector2 endPos, float thick, Color color)`

    Draw a line (using triangles/quads)"""

def DrawLineStrip(points: intptr, pointCount: int, color: color32) -> None:
    """Wraps `void DrawLineStrip(const Vector2 * points, int pointCount, Color color)`

    Draw lines sequence (using gl lines)"""

def DrawLineBezier(startPos: vec2, endPos: vec2, thick: float, color: color32) -> None:
    """Wraps `void DrawLineBezier(Vector2 startPos, Vector2 endPos, float thick, Color color)`

    Draw line segment cubic-bezier in-out interpolation"""

def DrawCircle(centerX: int, centerY: int, radius: float, color: color32) -> None:
    """Wraps `void DrawCircle(int centerX, int centerY, float radius, Color color)`

    Draw a color-filled circle"""

def DrawCircleSector(center: vec2, radius: float, startAngle: float, endAngle: float, segments: int, color: color32) -> None:
    """Wraps `void DrawCircleSector(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color)`

    Draw a piece of a circle"""

def DrawCircleSectorLines(center: vec2, radius: float, startAngle: float, endAngle: float, segments: int, color: color32) -> None:
    """Wraps `void DrawCircleSectorLines(Vector2 center, float radius, float startAngle, float endAngle, int segments, Color color)`

    Draw circle sector outline"""

def DrawCircleGradient(centerX: int, centerY: int, radius: float, inner: color32, outer: color32) -> None:
    """Wraps `void DrawCircleGradient(int centerX, int centerY, float radius, Color inner, Color outer)`

    Draw a gradient-filled circle"""

def DrawCircleV(center: vec2, radius: float, color: color32) -> None:
    """Wraps `void DrawCircleV(Vector2 center, float radius, Color color)`

    Draw a color-filled circle (Vector version)"""

def DrawCircleLines(centerX: int, centerY: int, radius: float, color: color32) -> None:
    """Wraps `void DrawCircleLines(int centerX, int centerY, float radius, Color color)`

    Draw circle outline"""

def DrawCircleLinesV(center: vec2, radius: float, color: color32) -> None:
    """Wraps `void DrawCircleLinesV(Vector2 center, float radius, Color color)`

    Draw circle outline (Vector version)"""

def DrawEllipse(centerX: int, centerY: int, radiusH: float, radiusV: float, color: color32) -> None:
    """Wraps `void DrawEllipse(int centerX, int centerY, float radiusH, float radiusV, Color color)`

    Draw ellipse"""

def DrawEllipseLines(centerX: int, centerY: int, radiusH: float, radiusV: float, color: color32) -> None:
    """Wraps `void DrawEllipseLines(int centerX, int centerY, float radiusH, float radiusV, Color color)`

    Draw ellipse outline"""

def DrawRing(center: vec2, innerRadius: float, outerRadius: float, startAngle: float, endAngle: float, segments: int, color: color32) -> None:
    """Wraps `void DrawRing(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color)`

    Draw ring"""

def DrawRingLines(center: vec2, innerRadius: float, outerRadius: float, startAngle: float, endAngle: float, segments: int, color: color32) -> None:
    """Wraps `void DrawRingLines(Vector2 center, float innerRadius, float outerRadius, float startAngle, float endAngle, int segments, Color color)`

    Draw ring outline"""

def DrawRectangle(posX: int, posY: int, width: int, height: int, color: color32) -> None:
    """Wraps `void DrawRectangle(int posX, int posY, int width, int height, Color color)`

    Draw a color-filled rectangle"""

def DrawRectangleV(position: vec2, size: vec2, color: color32) -> None:
    """Wraps `void DrawRectangleV(Vector2 position, Vector2 size, Color color)`

    Draw a color-filled rectangle (Vector version)"""

def DrawRectangleRec(rec: Rectangle, color: color32) -> None:
    """Wraps `void DrawRectangleRec(Rectangle rec, Color color)`

    Draw a color-filled rectangle"""

def DrawRectanglePro(rec: Rectangle, origin: vec2, rotation: float, color: color32) -> None:
    """Wraps `void DrawRectanglePro(Rectangle rec, Vector2 origin, float rotation, Color color)`

    Draw a color-filled rectangle with pro parameters"""

def DrawRectangleGradientV(posX: int, posY: int, width: int, height: int, top: color32, bottom: color32) -> None:
    """Wraps `void DrawRectangleGradientV(int posX, int posY, int width, int height, Color top, Color bottom)`

    Draw a vertical-gradient-filled rectangle"""

def DrawRectangleGradientH(posX: int, posY: int, width: int, height: int, left: color32, right: color32) -> None:
    """Wraps `void DrawRectangleGradientH(int posX, int posY, int width, int height, Color left, Color right)`

    Draw a horizontal-gradient-filled rectangle"""

def DrawRectangleGradientEx(rec: Rectangle, topLeft: color32, bottomLeft: color32, topRight: color32, bottomRight: color32) -> None:
    """Wraps `void DrawRectangleGradientEx(Rectangle rec, Color topLeft, Color bottomLeft, Color topRight, Color bottomRight)`

    Draw a gradient-filled rectangle with custom vertex colors"""

def DrawRectangleLines(posX: int, posY: int, width: int, height: int, color: color32) -> None:
    """Wraps `void DrawRectangleLines(int posX, int posY, int width, int height, Color color)`

    Draw rectangle outline"""

def DrawRectangleLinesEx(rec: Rectangle, lineThick: float, color: color32) -> None:
    """Wraps `void DrawRectangleLinesEx(Rectangle rec, float lineThick, Color color)`

    Draw rectangle outline with extended parameters"""

def DrawRectangleRounded(rec: Rectangle, roundness: float, segments: int, color: color32) -> None:
    """Wraps `void DrawRectangleRounded(Rectangle rec, float roundness, int segments, Color color)`

    Draw rectangle with rounded edges"""

def DrawRectangleRoundedLines(rec: Rectangle, roundness: float, segments: int, color: color32) -> None:
    """Wraps `void DrawRectangleRoundedLines(Rectangle rec, float roundness, int segments, Color color)`

    Draw rectangle lines with rounded edges"""

def DrawRectangleRoundedLinesEx(rec: Rectangle, roundness: float, segments: int, lineThick: float, color: color32) -> None:
    """Wraps `void DrawRectangleRoundedLinesEx(Rectangle rec, float roundness, int segments, float lineThick, Color color)`

    Draw rectangle with rounded edges outline"""

def DrawTriangle(v1: vec2, v2: vec2, v3: vec2, color: color32) -> None:
    """Wraps `void DrawTriangle(Vector2 v1, Vector2 v2, Vector2 v3, Color color)`

    Draw a color-filled triangle (vertex in counter-clockwise order!)"""

def DrawTriangleLines(v1: vec2, v2: vec2, v3: vec2, color: color32) -> None:
    """Wraps `void DrawTriangleLines(Vector2 v1, Vector2 v2, Vector2 v3, Color color)`

    Draw triangle outline (vertex in counter-clockwise order!)"""

def DrawTriangleFan(points: intptr, pointCount: int, color: color32) -> None:
    """Wraps `void DrawTriangleFan(const Vector2 * points, int pointCount, Color color)`

    Draw a triangle fan defined by points (first vertex is the center)"""

def DrawTriangleStrip(points: intptr, pointCount: int, color: color32) -> None:
    """Wraps `void DrawTriangleStrip(const Vector2 * points, int pointCount, Color color)`

    Draw a triangle strip defined by points"""

def DrawPoly(center: vec2, sides: int, radius: float, rotation: float, color: color32) -> None:
    """Wraps `void DrawPoly(Vector2 center, int sides, float radius, float rotation, Color color)`

    Draw a regular polygon (Vector version)"""

def DrawPolyLines(center: vec2, sides: int, radius: float, rotation: float, color: color32) -> None:
    """Wraps `void DrawPolyLines(Vector2 center, int sides, float radius, float rotation, Color color)`

    Draw a polygon outline of n sides"""

def DrawPolyLinesEx(center: vec2, sides: int, radius: float, rotation: float, lineThick: float, color: color32) -> None:
    """Wraps `void DrawPolyLinesEx(Vector2 center, int sides, float radius, float rotation, float lineThick, Color color)`

    Draw a polygon outline of n sides with extended parameters"""

def DrawSplineLinear(points: intptr, pointCount: int, thick: float, color: color32) -> None:
    """Wraps `void DrawSplineLinear(const Vector2 * points, int pointCount, float thick, Color color)`

    Draw spline: Linear, minimum 2 points"""

def DrawSplineBasis(points: intptr, pointCount: int, thick: float, color: color32) -> None:
    """Wraps `void DrawSplineBasis(const Vector2 * points, int pointCount, float thick, Color color)`

    Draw spline: B-Spline, minimum 4 points"""

def DrawSplineCatmullRom(points: intptr, pointCount: int, thick: float, color: color32) -> None:
    """Wraps `void DrawSplineCatmullRom(const Vector2 * points, int pointCount, float thick, Color color)`

    Draw spline: Catmull-Rom, minimum 4 points"""

def DrawSplineBezierQuadratic(points: intptr, pointCount: int, thick: float, color: color32) -> None:
    """Wraps `void DrawSplineBezierQuadratic(const Vector2 * points, int pointCount, float thick, Color color)`

    Draw spline: Quadratic Bezier, minimum 3 points (1 control point): [p1, c2, p3, c4...]"""

def DrawSplineBezierCubic(points: intptr, pointCount: int, thick: float, color: color32) -> None:
    """Wraps `void DrawSplineBezierCubic(const Vector2 * points, int pointCount, float thick, Color color)`

    Draw spline: Cubic Bezier, minimum 4 points (2 control points): [p1, c2, c3, p4, c5, c6...]"""

def DrawSplineSegmentLinear(p1: vec2, p2: vec2, thick: float, color: color32) -> None:
    """Wraps `void DrawSplineSegmentLinear(Vector2 p1, Vector2 p2, float thick, Color color)`

    Draw spline segment: Linear, 2 points"""

def DrawSplineSegmentBasis(p1: vec2, p2: vec2, p3: vec2, p4: vec2, thick: float, color: color32) -> None:
    """Wraps `void DrawSplineSegmentBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color)`

    Draw spline segment: B-Spline, 4 points"""

def DrawSplineSegmentCatmullRom(p1: vec2, p2: vec2, p3: vec2, p4: vec2, thick: float, color: color32) -> None:
    """Wraps `void DrawSplineSegmentCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float thick, Color color)`

    Draw spline segment: Catmull-Rom, 4 points"""

def DrawSplineSegmentBezierQuadratic(p1: vec2, c2: vec2, p3: vec2, thick: float, color: color32) -> None:
    """Wraps `void DrawSplineSegmentBezierQuadratic(Vector2 p1, Vector2 c2, Vector2 p3, float thick, Color color)`

    Draw spline segment: Quadratic Bezier, 2 points, 1 control point"""

def DrawSplineSegmentBezierCubic(p1: vec2, c2: vec2, c3: vec2, p4: vec2, thick: float, color: color32) -> None:
    """Wraps `void DrawSplineSegmentBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float thick, Color color)`

    Draw spline segment: Cubic Bezier, 2 points, 2 control points"""

def GetSplinePointLinear(startPos: vec2, endPos: vec2, t: float) -> vec2:
    """Wraps `Vector2 GetSplinePointLinear(Vector2 startPos, Vector2 endPos, float t)`

    Get (evaluate) spline point: Linear"""

def GetSplinePointBasis(p1: vec2, p2: vec2, p3: vec2, p4: vec2, t: float) -> vec2:
    """Wraps `Vector2 GetSplinePointBasis(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t)`

    Get (evaluate) spline point: B-Spline"""

def GetSplinePointCatmullRom(p1: vec2, p2: vec2, p3: vec2, p4: vec2, t: float) -> vec2:
    """Wraps `Vector2 GetSplinePointCatmullRom(Vector2 p1, Vector2 p2, Vector2 p3, Vector2 p4, float t)`

    Get (evaluate) spline point: Catmull-Rom"""

def GetSplinePointBezierQuad(p1: vec2, c2: vec2, p3: vec2, t: float) -> vec2:
    """Wraps `Vector2 GetSplinePointBezierQuad(Vector2 p1, Vector2 c2, Vector2 p3, float t)`

    Get (evaluate) spline point: Quadratic Bezier"""

def GetSplinePointBezierCubic(p1: vec2, c2: vec2, c3: vec2, p4: vec2, t: float) -> vec2:
    """Wraps `Vector2 GetSplinePointBezierCubic(Vector2 p1, Vector2 c2, Vector2 c3, Vector2 p4, float t)`

    Get (evaluate) spline point: Cubic Bezier"""

def CheckCollisionRecs(rec1: Rectangle, rec2: Rectangle) -> bool:
    """Wraps `bool CheckCollisionRecs(Rectangle rec1, Rectangle rec2)`

    Check collision between two rectangles"""

def CheckCollisionCircles(center1: vec2, radius1: float, center2: vec2, radius2: float) -> bool:
    """Wraps `bool CheckCollisionCircles(Vector2 center1, float radius1, Vector2 center2, float radius2)`

    Check collision between two circles"""

def CheckCollisionCircleRec(center: vec2, radius: float, rec: Rectangle) -> bool:
    """Wraps `bool CheckCollisionCircleRec(Vector2 center, float radius, Rectangle rec)`

    Check collision between circle and rectangle"""

def CheckCollisionCircleLine(center: vec2, radius: float, p1: vec2, p2: vec2) -> bool:
    """Wraps `bool CheckCollisionCircleLine(Vector2 center, float radius, Vector2 p1, Vector2 p2)`

    Check if circle collides with a line created betweeen two points [p1] and [p2]"""

def CheckCollisionPointRec(point: vec2, rec: Rectangle) -> bool:
    """Wraps `bool CheckCollisionPointRec(Vector2 point, Rectangle rec)`

    Check if point is inside rectangle"""

def CheckCollisionPointCircle(point: vec2, center: vec2, radius: float) -> bool:
    """Wraps `bool CheckCollisionPointCircle(Vector2 point, Vector2 center, float radius)`

    Check if point is inside circle"""

def CheckCollisionPointTriangle(point: vec2, p1: vec2, p2: vec2, p3: vec2) -> bool:
    """Wraps `bool CheckCollisionPointTriangle(Vector2 point, Vector2 p1, Vector2 p2, Vector2 p3)`

    Check if point is inside a triangle"""

def CheckCollisionPointLine(point: vec2, p1: vec2, p2: vec2, threshold: int) -> bool:
    """Wraps `bool CheckCollisionPointLine(Vector2 point, Vector2 p1, Vector2 p2, int threshold)`

    Check if point belongs to line created between two points [p1] and [p2] with defined margin in pixels [threshold]"""

def CheckCollisionPointPoly(point: vec2, points: intptr, pointCount: int) -> bool:
    """Wraps `bool CheckCollisionPointPoly(Vector2 point, const Vector2 * points, int pointCount)`

    Check if point is within a polygon described by array of vertices"""

def CheckCollisionLines(startPos1: vec2, endPos1: vec2, startPos2: vec2, endPos2: vec2, collisionPoint: intptr) -> bool:
    """Wraps `bool CheckCollisionLines(Vector2 startPos1, Vector2 endPos1, Vector2 startPos2, Vector2 endPos2, Vector2 * collisionPoint)`

    Check the collision between two lines defined by two points each, returns collision point by reference"""

def GetCollisionRec(rec1: Rectangle, rec2: Rectangle) -> Rectangle:
    """Wraps `Rectangle GetCollisionRec(Rectangle rec1, Rectangle rec2)`

    Get collision rectangle for two rectangles collision"""

def LoadImage(fileName: str) -> Image:
    """Wraps `Image LoadImage(const char * fileName)`

    Load image from file into CPU memory (RAM)"""

def LoadImageRaw(fileName: str, width: int, height: int, format: int, headerSize: int) -> Image:
    """Wraps `Image LoadImageRaw(const char * fileName, int width, int height, int format, int headerSize)`

    Load image from RAW file data"""

def LoadImageAnim(fileName: str, frames: intptr) -> Image:
    """Wraps `Image LoadImageAnim(const char * fileName, int * frames)`

    Load image sequence from file (frames appended to image.data)"""

def LoadImageAnimFromMemory(fileType: str, fileData: intptr, dataSize: int, frames: intptr) -> Image:
    """Wraps `Image LoadImageAnimFromMemory(const char * fileType, const unsigned char * fileData, int dataSize, int * frames)`

    Load image sequence from memory buffer"""

def LoadImageFromMemory(fileType: str, fileData: intptr, dataSize: int) -> Image:
    """Wraps `Image LoadImageFromMemory(const char * fileType, const unsigned char * fileData, int dataSize)`

    Load image from memory buffer, fileType refers to extension: i.e. '.png'"""

def LoadImageFromTexture(texture: Texture2D) -> Image:
    """Wraps `Image LoadImageFromTexture(Texture2D texture)`

    Load image from GPU texture data"""

def LoadImageFromScreen() -> Image:
    """Wraps `Image LoadImageFromScreen()`

    Load image from screen buffer and (screenshot)"""

def IsImageValid(image: Image) -> bool:
    """Wraps `bool IsImageValid(Image image)`

    Check if an image is valid (data and parameters)"""

def UnloadImage(image: Image) -> None:
    """Wraps `void UnloadImage(Image image)`

    Unload image from CPU memory (RAM)"""

def ExportImage(image: Image, fileName: str) -> bool:
    """Wraps `bool ExportImage(Image image, const char * fileName)`

    Export image data to file, returns true on success"""

def ExportImageToMemory(image: Image, fileType: str, fileSize: intptr) -> intptr:
    """Wraps `unsigned char * ExportImageToMemory(Image image, const char * fileType, int * fileSize)`

    Export image to memory buffer"""

def ExportImageAsCode(image: Image, fileName: str) -> bool:
    """Wraps `bool ExportImageAsCode(Image image, const char * fileName)`

    Export image as code file defining an array of bytes, returns true on success"""

def GenImageColor(width: int, height: int, color: color32) -> Image:
    """Wraps `Image GenImageColor(int width, int height, Color color)`

    Generate image: plain color"""

def GenImageGradientLinear(width: int, height: int, direction: int, start: color32, end: color32) -> Image:
    """Wraps `Image GenImageGradientLinear(int width, int height, int direction, Color start, Color end)`

    Generate image: linear gradient, direction in degrees [0..360], 0=Vertical gradient"""

def GenImageGradientRadial(width: int, height: int, density: float, inner: color32, outer: color32) -> Image:
    """Wraps `Image GenImageGradientRadial(int width, int height, float density, Color inner, Color outer)`

    Generate image: radial gradient"""

def GenImageGradientSquare(width: int, height: int, density: float, inner: color32, outer: color32) -> Image:
    """Wraps `Image GenImageGradientSquare(int width, int height, float density, Color inner, Color outer)`

    Generate image: square gradient"""

def GenImageChecked(width: int, height: int, checksX: int, checksY: int, col1: color32, col2: color32) -> Image:
    """Wraps `Image GenImageChecked(int width, int height, int checksX, int checksY, Color col1, Color col2)`

    Generate image: checked"""

def GenImageWhiteNoise(width: int, height: int, factor: float) -> Image:
    """Wraps `Image GenImageWhiteNoise(int width, int height, float factor)`

    Generate image: white noise"""

def GenImagePerlinNoise(width: int, height: int, offsetX: int, offsetY: int, scale: float) -> Image:
    """Wraps `Image GenImagePerlinNoise(int width, int height, int offsetX, int offsetY, float scale)`

    Generate image: perlin noise"""

def GenImageCellular(width: int, height: int, tileSize: int) -> Image:
    """Wraps `Image GenImageCellular(int width, int height, int tileSize)`

    Generate image: cellular algorithm, bigger tileSize means bigger cells"""

def GenImageText(width: int, height: int, text: str) -> Image:
    """Wraps `Image GenImageText(int width, int height, const char * text)`

    Generate image: grayscale image from text data"""

def ImageCopy(image: Image) -> Image:
    """Wraps `Image ImageCopy(Image image)`

    Create an image duplicate (useful for transformations)"""

def ImageFromImage(image: Image, rec: Rectangle) -> Image:
    """Wraps `Image ImageFromImage(Image image, Rectangle rec)`

    Create an image from another image piece"""

def ImageFromChannel(image: Image, selectedChannel: int) -> Image:
    """Wraps `Image ImageFromChannel(Image image, int selectedChannel)`

    Create an image from a selected channel of another image (GRAYSCALE)"""

def ImageText(text: str, fontSize: int, color: color32) -> Image:
    """Wraps `Image ImageText(const char * text, int fontSize, Color color)`

    Create an image from text (default font)"""

def ImageTextEx(font: Font, text: str, fontSize: float, spacing: float, tint: color32) -> Image:
    """Wraps `Image ImageTextEx(Font font, const char * text, float fontSize, float spacing, Color tint)`

    Create an image from text (custom sprite font)"""

def ImageFormat(image: intptr, newFormat: int) -> None:
    """Wraps `void ImageFormat(Image * image, int newFormat)`

    Convert image data to desired format"""

def ImageToPOT(image: intptr, fill: color32) -> None:
    """Wraps `void ImageToPOT(Image * image, Color fill)`

    Convert image to POT (power-of-two)"""

def ImageCrop(image: intptr, crop: Rectangle) -> None:
    """Wraps `void ImageCrop(Image * image, Rectangle crop)`

    Crop an image to a defined rectangle"""

def ImageAlphaCrop(image: intptr, threshold: float) -> None:
    """Wraps `void ImageAlphaCrop(Image * image, float threshold)`

    Crop image depending on alpha value"""

def ImageAlphaClear(image: intptr, color: color32, threshold: float) -> None:
    """Wraps `void ImageAlphaClear(Image * image, Color color, float threshold)`

    Clear alpha channel to desired color"""

def ImageAlphaMask(image: intptr, alphaMask: Image) -> None:
    """Wraps `void ImageAlphaMask(Image * image, Image alphaMask)`

    Apply alpha mask to image"""

def ImageAlphaPremultiply(image: intptr) -> None:
    """Wraps `void ImageAlphaPremultiply(Image * image)`

    Premultiply alpha channel"""

def ImageBlurGaussian(image: intptr, blurSize: int) -> None:
    """Wraps `void ImageBlurGaussian(Image * image, int blurSize)`

    Apply Gaussian blur using a box blur approximation"""

def ImageKernelConvolution(image: intptr, kernel: intptr, kernelSize: int) -> None:
    """Wraps `void ImageKernelConvolution(Image * image, const float * kernel, int kernelSize)`

    Apply custom square convolution kernel to image"""

def ImageResize(image: intptr, newWidth: int, newHeight: int) -> None:
    """Wraps `void ImageResize(Image * image, int newWidth, int newHeight)`

    Resize image (Bicubic scaling algorithm)"""

def ImageResizeNN(image: intptr, newWidth: int, newHeight: int) -> None:
    """Wraps `void ImageResizeNN(Image * image, int newWidth, int newHeight)`

    Resize image (Nearest-Neighbor scaling algorithm)"""

def ImageResizeCanvas(image: intptr, newWidth: int, newHeight: int, offsetX: int, offsetY: int, fill: color32) -> None:
    """Wraps `void ImageResizeCanvas(Image * image, int newWidth, int newHeight, int offsetX, int offsetY, Color fill)`

    Resize canvas and fill with color"""

def ImageMipmaps(image: intptr) -> None:
    """Wraps `void ImageMipmaps(Image * image)`

    Compute all mipmap levels for a provided image"""

def ImageDither(image: intptr, rBpp: int, gBpp: int, bBpp: int, aBpp: int) -> None:
    """Wraps `void ImageDither(Image * image, int rBpp, int gBpp, int bBpp, int aBpp)`

    Dither image data to 16bpp or lower (Floyd-Steinberg dithering)"""

def ImageFlipVertical(image: intptr) -> None:
    """Wraps `void ImageFlipVertical(Image * image)`

    Flip image vertically"""

def ImageFlipHorizontal(image: intptr) -> None:
    """Wraps `void ImageFlipHorizontal(Image * image)`

    Flip image horizontally"""

def ImageRotate(image: intptr, degrees: int) -> None:
    """Wraps `void ImageRotate(Image * image, int degrees)`

    Rotate image by input angle in degrees (-359 to 359)"""

def ImageRotateCW(image: intptr) -> None:
    """Wraps `void ImageRotateCW(Image * image)`

    Rotate image clockwise 90deg"""

def ImageRotateCCW(image: intptr) -> None:
    """Wraps `void ImageRotateCCW(Image * image)`

    Rotate image counter-clockwise 90deg"""

def ImageColorTint(image: intptr, color: color32) -> None:
    """Wraps `void ImageColorTint(Image * image, Color color)`

    Modify image color: tint"""

def ImageColorInvert(image: intptr) -> None:
    """Wraps `void ImageColorInvert(Image * image)`

    Modify image color: invert"""

def ImageColorGrayscale(image: intptr) -> None:
    """Wraps `void ImageColorGrayscale(Image * image)`

    Modify image color: grayscale"""

def ImageColorContrast(image: intptr, contrast: float) -> None:
    """Wraps `void ImageColorContrast(Image * image, float contrast)`

    Modify image color: contrast (-100 to 100)"""

def ImageColorBrightness(image: intptr, brightness: int) -> None:
    """Wraps `void ImageColorBrightness(Image * image, int brightness)`

    Modify image color: brightness (-255 to 255)"""

def ImageColorReplace(image: intptr, color: color32, replace: color32) -> None:
    """Wraps `void ImageColorReplace(Image * image, Color color, Color replace)`

    Modify image color: replace color"""

def LoadImageColors(image: Image) -> intptr:
    """Wraps `Color * LoadImageColors(Image image)`

    Load color data from image as a Color array (RGBA - 32bit)"""

def LoadImagePalette(image: Image, maxPaletteSize: int, colorCount: intptr) -> intptr:
    """Wraps `Color * LoadImagePalette(Image image, int maxPaletteSize, int * colorCount)`

    Load colors palette from image as a Color array (RGBA - 32bit)"""

def UnloadImageColors(colors: intptr) -> None:
    """Wraps `void UnloadImageColors(Color * colors)`

    Unload color data loaded with LoadImageColors()"""

def UnloadImagePalette(colors: intptr) -> None:
    """Wraps `void UnloadImagePalette(Color * colors)`

    Unload colors palette loaded with LoadImagePalette()"""

def GetImageAlphaBorder(image: Image, threshold: float) -> Rectangle:
    """Wraps `Rectangle GetImageAlphaBorder(Image image, float threshold)`

    Get image alpha border rectangle"""

def GetImageColor(image: Image, x: int, y: int) -> color32:
    """Wraps `Color GetImageColor(Image image, int x, int y)`

    Get image pixel color at (x, y) position"""

def ImageClearBackground(dst: intptr, color: color32) -> None:
    """Wraps `void ImageClearBackground(Image * dst, Color color)`

    Clear image background with given color"""

def ImageDrawPixel(dst: intptr, posX: int, posY: int, color: color32) -> None:
    """Wraps `void ImageDrawPixel(Image * dst, int posX, int posY, Color color)`

    Draw pixel within an image"""

def ImageDrawPixelV(dst: intptr, position: vec2, color: color32) -> None:
    """Wraps `void ImageDrawPixelV(Image * dst, Vector2 position, Color color)`

    Draw pixel within an image (Vector version)"""

def ImageDrawLine(dst: intptr, startPosX: int, startPosY: int, endPosX: int, endPosY: int, color: color32) -> None:
    """Wraps `void ImageDrawLine(Image * dst, int startPosX, int startPosY, int endPosX, int endPosY, Color color)`

    Draw line within an image"""

def ImageDrawLineV(dst: intptr, start: vec2, end: vec2, color: color32) -> None:
    """Wraps `void ImageDrawLineV(Image * dst, Vector2 start, Vector2 end, Color color)`

    Draw line within an image (Vector version)"""

def ImageDrawLineEx(dst: intptr, start: vec2, end: vec2, thick: int, color: color32) -> None:
    """Wraps `void ImageDrawLineEx(Image * dst, Vector2 start, Vector2 end, int thick, Color color)`

    Draw a line defining thickness within an image"""

def ImageDrawCircle(dst: intptr, centerX: int, centerY: int, radius: int, color: color32) -> None:
    """Wraps `void ImageDrawCircle(Image * dst, int centerX, int centerY, int radius, Color color)`

    Draw a filled circle within an image"""

def ImageDrawCircleV(dst: intptr, center: vec2, radius: int, color: color32) -> None:
    """Wraps `void ImageDrawCircleV(Image * dst, Vector2 center, int radius, Color color)`

    Draw a filled circle within an image (Vector version)"""

def ImageDrawCircleLines(dst: intptr, centerX: int, centerY: int, radius: int, color: color32) -> None:
    """Wraps `void ImageDrawCircleLines(Image * dst, int centerX, int centerY, int radius, Color color)`

    Draw circle outline within an image"""

def ImageDrawCircleLinesV(dst: intptr, center: vec2, radius: int, color: color32) -> None:
    """Wraps `void ImageDrawCircleLinesV(Image * dst, Vector2 center, int radius, Color color)`

    Draw circle outline within an image (Vector version)"""

def ImageDrawRectangle(dst: intptr, posX: int, posY: int, width: int, height: int, color: color32) -> None:
    """Wraps `void ImageDrawRectangle(Image * dst, int posX, int posY, int width, int height, Color color)`

    Draw rectangle within an image"""

def ImageDrawRectangleV(dst: intptr, position: vec2, size: vec2, color: color32) -> None:
    """Wraps `void ImageDrawRectangleV(Image * dst, Vector2 position, Vector2 size, Color color)`

    Draw rectangle within an image (Vector version)"""

def ImageDrawRectangleRec(dst: intptr, rec: Rectangle, color: color32) -> None:
    """Wraps `void ImageDrawRectangleRec(Image * dst, Rectangle rec, Color color)`

    Draw rectangle within an image"""

def ImageDrawRectangleLines(dst: intptr, rec: Rectangle, thick: int, color: color32) -> None:
    """Wraps `void ImageDrawRectangleLines(Image * dst, Rectangle rec, int thick, Color color)`

    Draw rectangle lines within an image"""

def ImageDrawTriangle(dst: intptr, v1: vec2, v2: vec2, v3: vec2, color: color32) -> None:
    """Wraps `void ImageDrawTriangle(Image * dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color)`

    Draw triangle within an image"""

def ImageDrawTriangleEx(dst: intptr, v1: vec2, v2: vec2, v3: vec2, c1: color32, c2: color32, c3: color32) -> None:
    """Wraps `void ImageDrawTriangleEx(Image * dst, Vector2 v1, Vector2 v2, Vector2 v3, Color c1, Color c2, Color c3)`

    Draw triangle with interpolated colors within an image"""

def ImageDrawTriangleLines(dst: intptr, v1: vec2, v2: vec2, v3: vec2, color: color32) -> None:
    """Wraps `void ImageDrawTriangleLines(Image * dst, Vector2 v1, Vector2 v2, Vector2 v3, Color color)`

    Draw triangle outline within an image"""

def ImageDrawTriangleFan(dst: intptr, points: intptr, pointCount: int, color: color32) -> None:
    """Wraps `void ImageDrawTriangleFan(Image * dst, Vector2 * points, int pointCount, Color color)`

    Draw a triangle fan defined by points within an image (first vertex is the center)"""

def ImageDrawTriangleStrip(dst: intptr, points: intptr, pointCount: int, color: color32) -> None:
    """Wraps `void ImageDrawTriangleStrip(Image * dst, Vector2 * points, int pointCount, Color color)`

    Draw a triangle strip defined by points within an image"""

def ImageDraw(dst: intptr, src: Image, srcRec: Rectangle, dstRec: Rectangle, tint: color32) -> None:
    """Wraps `void ImageDraw(Image * dst, Image src, Rectangle srcRec, Rectangle dstRec, Color tint)`

    Draw a source image within a destination image (tint applied to source)"""

def ImageDrawText(dst: intptr, text: str, posX: int, posY: int, fontSize: int, color: color32) -> None:
    """Wraps `void ImageDrawText(Image * dst, const char * text, int posX, int posY, int fontSize, Color color)`

    Draw text (using default font) within an image (destination)"""

def ImageDrawTextEx(dst: intptr, font: Font, text: str, position: vec2, fontSize: float, spacing: float, tint: color32) -> None:
    """Wraps `void ImageDrawTextEx(Image * dst, Font font, const char * text, Vector2 position, float fontSize, float spacing, Color tint)`

    Draw text (custom sprite font) within an image (destination)"""

def LoadTexture(fileName: str) -> Texture2D:
    """Wraps `Texture2D LoadTexture(const char * fileName)`

    Load texture from file into GPU memory (VRAM)"""

def LoadTextureFromImage(image: Image) -> Texture2D:
    """Wraps `Texture2D LoadTextureFromImage(Image image)`

    Load texture from image data"""

def LoadTextureCubemap(image: Image, layout: int) -> TextureCubemap:
    """Wraps `TextureCubemap LoadTextureCubemap(Image image, int layout)`

    Load cubemap from image, multiple image cubemap layouts supported"""

def LoadRenderTexture(width: int, height: int) -> RenderTexture2D:
    """Wraps `RenderTexture2D LoadRenderTexture(int width, int height)`

    Load texture for rendering (framebuffer)"""

def IsTextureValid(texture: Texture2D) -> bool:
    """Wraps `bool IsTextureValid(Texture2D texture)`

    Check if a texture is valid (loaded in GPU)"""

def UnloadTexture(texture: Texture2D) -> None:
    """Wraps `void UnloadTexture(Texture2D texture)`

    Unload texture from GPU memory (VRAM)"""

def IsRenderTextureValid(target: RenderTexture2D) -> bool:
    """Wraps `bool IsRenderTextureValid(RenderTexture2D target)`

    Check if a render texture is valid (loaded in GPU)"""

def UnloadRenderTexture(target: RenderTexture2D) -> None:
    """Wraps `void UnloadRenderTexture(RenderTexture2D target)`

    Unload render texture from GPU memory (VRAM)"""

def UpdateTexture(texture: Texture2D, pixels: intptr) -> None:
    """Wraps `void UpdateTexture(Texture2D texture, const void * pixels)`

    Update GPU texture with new data"""

def UpdateTextureRec(texture: Texture2D, rec: Rectangle, pixels: intptr) -> None:
    """Wraps `void UpdateTextureRec(Texture2D texture, Rectangle rec, const void * pixels)`

    Update GPU texture rectangle with new data"""

def GenTextureMipmaps(texture: intptr) -> None:
    """Wraps `void GenTextureMipmaps(Texture2D * texture)`

    Generate GPU mipmaps for a texture"""

def SetTextureFilter(texture: Texture2D, filter: int) -> None:
    """Wraps `void SetTextureFilter(Texture2D texture, int filter)`

    Set texture scaling filter mode"""

def SetTextureWrap(texture: Texture2D, wrap: int) -> None:
    """Wraps `void SetTextureWrap(Texture2D texture, int wrap)`

    Set texture wrapping mode"""

def DrawTexture(texture: Texture2D, posX: int, posY: int, tint: color32) -> None:
    """Wraps `void DrawTexture(Texture2D texture, int posX, int posY, Color tint)`

    Draw a Texture2D"""

def DrawTextureV(texture: Texture2D, position: vec2, tint: color32) -> None:
    """Wraps `void DrawTextureV(Texture2D texture, Vector2 position, Color tint)`

    Draw a Texture2D with position defined as Vector2"""

def DrawTextureEx(texture: Texture2D, position: vec2, rotation: float, scale: float, tint: color32) -> None:
    """Wraps `void DrawTextureEx(Texture2D texture, Vector2 position, float rotation, float scale, Color tint)`

    Draw a Texture2D with extended parameters"""

def DrawTextureRec(texture: Texture2D, source: Rectangle, position: vec2, tint: color32) -> None:
    """Wraps `void DrawTextureRec(Texture2D texture, Rectangle source, Vector2 position, Color tint)`

    Draw a part of a texture defined by a rectangle"""

def DrawTexturePro(texture: Texture2D, source: Rectangle, dest: Rectangle, origin: vec2, rotation: float, tint: color32) -> None:
    """Wraps `void DrawTexturePro(Texture2D texture, Rectangle source, Rectangle dest, Vector2 origin, float rotation, Color tint)`

    Draw a part of a texture defined by a rectangle with 'pro' parameters"""

def DrawTextureNPatch(texture: Texture2D, nPatchInfo: NPatchInfo, dest: Rectangle, origin: vec2, rotation: float, tint: color32) -> None:
    """Wraps `void DrawTextureNPatch(Texture2D texture, NPatchInfo nPatchInfo, Rectangle dest, Vector2 origin, float rotation, Color tint)`

    Draws a texture (or part of it) that stretches or shrinks nicely"""

def ColorIsEqual(col1: color32, col2: color32) -> bool:
    """Wraps `bool ColorIsEqual(Color col1, Color col2)`

    Check if two colors are equal"""

def Fade(color: color32, alpha: float) -> color32:
    """Wraps `Color Fade(Color color, float alpha)`

    Get color with alpha applied, alpha goes from 0.0f to 1.0f"""

def ColorToInt(color: color32) -> int:
    """Wraps `int ColorToInt(Color color)`

    Get hexadecimal value for a Color (0xRRGGBBAA)"""

def ColorNormalize(color: color32) -> Vector4:
    """Wraps `Vector4 ColorNormalize(Color color)`

    Get Color normalized as float [0..1]"""

def ColorFromNormalized(normalized: Vector4) -> color32:
    """Wraps `Color ColorFromNormalized(Vector4 normalized)`

    Get Color from normalized values [0..1]"""

def ColorToHSV(color: color32) -> vec3:
    """Wraps `Vector3 ColorToHSV(Color color)`

    Get HSV values for a Color, hue [0..360], saturation/value [0..1]"""

def ColorFromHSV(hue: float, saturation: float, value: float) -> color32:
    """Wraps `Color ColorFromHSV(float hue, float saturation, float value)`

    Get a Color from HSV values, hue [0..360], saturation/value [0..1]"""

def ColorTint(color: color32, tint: color32) -> color32:
    """Wraps `Color ColorTint(Color color, Color tint)`

    Get color multiplied with another color"""

def ColorBrightness(color: color32, factor: float) -> color32:
    """Wraps `Color ColorBrightness(Color color, float factor)`

    Get color with brightness correction, brightness factor goes from -1.0f to 1.0f"""

def ColorContrast(color: color32, contrast: float) -> color32:
    """Wraps `Color ColorContrast(Color color, float contrast)`

    Get color with contrast correction, contrast values between -1.0f and 1.0f"""

def ColorAlpha(color: color32, alpha: float) -> color32:
    """Wraps `Color ColorAlpha(Color color, float alpha)`

    Get color with alpha applied, alpha goes from 0.0f to 1.0f"""

def ColorAlphaBlend(dst: color32, src: color32, tint: color32) -> color32:
    """Wraps `Color ColorAlphaBlend(Color dst, Color src, Color tint)`

    Get src alpha-blended into dst color with tint"""

def ColorLerp(color1: color32, color2: color32, factor: float) -> color32:
    """Wraps `Color ColorLerp(Color color1, Color color2, float factor)`

    Get color lerp interpolation between two colors, factor [0.0f..1.0f]"""

def GetColor(hexValue: int) -> color32:
    """Wraps `Color GetColor(unsigned int hexValue)`

    Get Color structure from hexadecimal value"""

def GetPixelColor(srcPtr: intptr, format: int) -> color32:
    """Wraps `Color GetPixelColor(void * srcPtr, int format)`

    Get Color from a source pixel pointer of certain format"""

def SetPixelColor(dstPtr: intptr, color: color32, format: int) -> None:
    """Wraps `void SetPixelColor(void * dstPtr, Color color, int format)`

    Set color formatted into destination pixel pointer"""

def GetPixelDataSize(width: int, height: int, format: int) -> int:
    """Wraps `int GetPixelDataSize(int width, int height, int format)`

    Get pixel data size in bytes for certain format"""

def GetFontDefault() -> Font:
    """Wraps `Font GetFontDefault()`

    Get the default Font"""

def LoadFont(fileName: str) -> Font:
    """Wraps `Font LoadFont(const char * fileName)`

    Load font from file into GPU memory (VRAM)"""

def LoadFontEx(fileName: str, fontSize: int, codepoints: intptr, codepointCount: int) -> Font:
    """Wraps `Font LoadFontEx(const char * fileName, int fontSize, int * codepoints, int codepointCount)`

    Load font from file with extended parameters, use NULL for codepoints and 0 for codepointCount to load the default character set, font size is provided in pixels height"""

def LoadFontFromImage(image: Image, key: color32, firstChar: int) -> Font:
    """Wraps `Font LoadFontFromImage(Image image, Color key, int firstChar)`

    Load font from Image (XNA style)"""

def LoadFontFromMemory(fileType: str, fileData: intptr, dataSize: int, fontSize: int, codepoints: intptr, codepointCount: int) -> Font:
    """Wraps `Font LoadFontFromMemory(const char * fileType, const unsigned char * fileData, int dataSize, int fontSize, int * codepoints, int codepointCount)`

    Load font from memory buffer, fileType refers to extension: i.e. '.ttf'"""

def IsFontValid(font: Font) -> bool:
    """Wraps `bool IsFontValid(Font font)`

    Check if a font is valid (font data loaded, WARNING: GPU texture not checked)"""

def LoadFontData(fileData: intptr, dataSize: int, fontSize: int, codepoints: intptr, codepointCount: int, type: int) -> intptr:
    """Wraps `GlyphInfo * LoadFontData(const unsigned char * fileData, int dataSize, int fontSize, int * codepoints, int codepointCount, int type)`

    Load font data for further use"""

def GenImageFontAtlas(glyphs: intptr, glyphRecs: intptr, glyphCount: int, fontSize: int, padding: int, packMethod: int) -> Image:
    """Wraps `Image GenImageFontAtlas(const GlyphInfo * glyphs, Rectangle ** glyphRecs, int glyphCount, int fontSize, int padding, int packMethod)`

    Generate image font atlas using chars info"""

def UnloadFontData(glyphs: intptr, glyphCount: int) -> None:
    """Wraps `void UnloadFontData(GlyphInfo * glyphs, int glyphCount)`

    Unload font chars info data (RAM)"""

def UnloadFont(font: Font) -> None:
    """Wraps `void UnloadFont(Font font)`

    Unload font from GPU memory (VRAM)"""

def ExportFontAsCode(font: Font, fileName: str) -> bool:
    """Wraps `bool ExportFontAsCode(Font font, const char * fileName)`

    Export font as code file, returns true on success"""

def DrawFPS(posX: int, posY: int) -> None:
    """Wraps `void DrawFPS(int posX, int posY)`

    Draw current FPS"""

def DrawText(text: str, posX: int, posY: int, fontSize: int, color: color32) -> None:
    """Wraps `void DrawText(const char * text, int posX, int posY, int fontSize, Color color)`

    Draw text (using default font)"""

def DrawTextEx(font: Font, text: str, position: vec2, fontSize: float, spacing: float, tint: color32) -> None:
    """Wraps `void DrawTextEx(Font font, const char * text, Vector2 position, float fontSize, float spacing, Color tint)`

    Draw text using font and additional parameters"""

def DrawTextPro(font: Font, text: str, position: vec2, origin: vec2, rotation: float, fontSize: float, spacing: float, tint: color32) -> None:
    """Wraps `void DrawTextPro(Font font, const char * text, Vector2 position, Vector2 origin, float rotation, float fontSize, float spacing, Color tint)`

    Draw text using Font and pro parameters (rotation)"""

def DrawTextCodepoint(font: Font, codepoint: int, position: vec2, fontSize: float, tint: color32) -> None:
    """Wraps `void DrawTextCodepoint(Font font, int codepoint, Vector2 position, float fontSize, Color tint)`

    Draw one character (codepoint)"""

def DrawTextCodepoints(font: Font, codepoints: intptr, codepointCount: int, position: vec2, fontSize: float, spacing: float, tint: color32) -> None:
    """Wraps `void DrawTextCodepoints(Font font, const int * codepoints, int codepointCount, Vector2 position, float fontSize, float spacing, Color tint)`

    Draw multiple character (codepoint)"""

def SetTextLineSpacing(spacing: int) -> None:
    """Wraps `void SetTextLineSpacing(int spacing)`

    Set vertical line spacing when drawing with line-breaks"""

def MeasureText(text: str, fontSize: int) -> int:
    """Wraps `int MeasureText(const char * text, int fontSize)`

    Measure string width for default font"""

def MeasureTextEx(font: Font, text: str, fontSize: float, spacing: float) -> vec2:
    """Wraps `Vector2 MeasureTextEx(Font font, const char * text, float fontSize, float spacing)`

    Measure string size for Font"""

def GetGlyphIndex(font: Font, codepoint: int) -> int:
    """Wraps `int GetGlyphIndex(Font font, int codepoint)`

    Get glyph index position in font for a codepoint (unicode character), fallback to '?' if not found"""

def GetGlyphInfo(font: Font, codepoint: int) -> GlyphInfo:
    """Wraps `GlyphInfo GetGlyphInfo(Font font, int codepoint)`

    Get glyph font info data for a codepoint (unicode character), fallback to '?' if not found"""

def GetGlyphAtlasRec(font: Font, codepoint: int) -> Rectangle:
    """Wraps `Rectangle GetGlyphAtlasRec(Font font, int codepoint)`

    Get glyph rectangle in font atlas for a codepoint (unicode character), fallback to '?' if not found"""

def LoadUTF8(codepoints: intptr, length: int) -> intptr:
    """Wraps `char * LoadUTF8(const int * codepoints, int length)`

    Load UTF-8 text encoded from codepoints array"""

def UnloadUTF8(text: intptr) -> None:
    """Wraps `void UnloadUTF8(char * text)`

    Unload UTF-8 text encoded from codepoints array"""

def LoadCodepoints(text: str, count: intptr) -> intptr:
    """Wraps `int * LoadCodepoints(const char * text, int * count)`

    Load all codepoints from a UTF-8 text string, codepoints count returned by parameter"""

def UnloadCodepoints(codepoints: intptr) -> None:
    """Wraps `void UnloadCodepoints(int * codepoints)`

    Unload codepoints data from memory"""

def GetCodepointCount(text: str) -> int:
    """Wraps `int GetCodepointCount(const char * text)`

    Get total number of codepoints in a UTF-8 encoded string"""

def GetCodepoint(text: str, codepointSize: intptr) -> int:
    """Wraps `int GetCodepoint(const char * text, int * codepointSize)`

    Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure"""

def GetCodepointNext(text: str, codepointSize: intptr) -> int:
    """Wraps `int GetCodepointNext(const char * text, int * codepointSize)`

    Get next codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure"""

def GetCodepointPrevious(text: str, codepointSize: intptr) -> int:
    """Wraps `int GetCodepointPrevious(const char * text, int * codepointSize)`

    Get previous codepoint in a UTF-8 encoded string, 0x3f('?') is returned on failure"""

def CodepointToUTF8(codepoint: int, utf8Size: intptr) -> str:
    """Wraps `const char * CodepointToUTF8(int codepoint, int * utf8Size)`

    Encode one codepoint into UTF-8 byte array (array length returned as parameter)"""

def TextCopy(dst: intptr, src: str) -> int:
    """Wraps `int TextCopy(char * dst, const char * src)`

    Copy one string to another, returns bytes copied"""

def TextIsEqual(text1: str, text2: str) -> bool:
    """Wraps `bool TextIsEqual(const char * text1, const char * text2)`

    Check if two text string are equal"""

def TextLength(text: str) -> int:
    """Wraps `unsigned int TextLength(const char * text)`

    Get text length, checks for '\0' ending"""

def TextSubtext(text: str, position: int, length: int) -> str:
    """Wraps `const char * TextSubtext(const char * text, int position, int length)`

    Get a piece of a text string"""

def TextReplace(text: str, replace: str, by: str) -> intptr:
    """Wraps `char * TextReplace(const char * text, const char * replace, const char * by)`

    Replace text string (WARNING: memory must be freed!)"""

def TextInsert(text: str, insert: str, position: int) -> intptr:
    """Wraps `char * TextInsert(const char * text, const char * insert, int position)`

    Insert text in a position (WARNING: memory must be freed!)"""

def TextJoin(textList: intptr, count: int, delimiter: str) -> str:
    """Wraps `const char * TextJoin(const char ** textList, int count, const char * delimiter)`

    Join text strings with delimiter"""

def TextSplit(text: str, delimiter: int, count: intptr) -> intptr:
    """Wraps `const char ** TextSplit(const char * text, char delimiter, int * count)`

    Split text into multiple strings"""

def TextAppend(text: intptr, append: str, position: intptr) -> None:
    """Wraps `void TextAppend(char * text, const char * append, int * position)`

    Append text at specific position and move cursor!"""

def TextFindIndex(text: str, find: str) -> int:
    """Wraps `int TextFindIndex(const char * text, const char * find)`

    Find first text occurrence within a string"""

def TextToUpper(text: str) -> str:
    """Wraps `const char * TextToUpper(const char * text)`

    Get upper case version of provided string"""

def TextToLower(text: str) -> str:
    """Wraps `const char * TextToLower(const char * text)`

    Get lower case version of provided string"""

def TextToPascal(text: str) -> str:
    """Wraps `const char * TextToPascal(const char * text)`

    Get Pascal case notation version of provided string"""

def TextToSnake(text: str) -> str:
    """Wraps `const char * TextToSnake(const char * text)`

    Get Snake case notation version of provided string"""

def TextToCamel(text: str) -> str:
    """Wraps `const char * TextToCamel(const char * text)`

    Get Camel case notation version of provided string"""

def TextToInteger(text: str) -> int:
    """Wraps `int TextToInteger(const char * text)`

    Get integer value from text (negative values not supported)"""

def TextToFloat(text: str) -> float:
    """Wraps `float TextToFloat(const char * text)`

    Get float value from text (negative values not supported)"""

def DrawLine3D(startPos: vec3, endPos: vec3, color: color32) -> None:
    """Wraps `void DrawLine3D(Vector3 startPos, Vector3 endPos, Color color)`

    Draw a line in 3D world space"""

def DrawPoint3D(position: vec3, color: color32) -> None:
    """Wraps `void DrawPoint3D(Vector3 position, Color color)`

    Draw a point in 3D space, actually a small line"""

def DrawCircle3D(center: vec3, radius: float, rotationAxis: vec3, rotationAngle: float, color: color32) -> None:
    """Wraps `void DrawCircle3D(Vector3 center, float radius, Vector3 rotationAxis, float rotationAngle, Color color)`

    Draw a circle in 3D world space"""

def DrawTriangle3D(v1: vec3, v2: vec3, v3: vec3, color: color32) -> None:
    """Wraps `void DrawTriangle3D(Vector3 v1, Vector3 v2, Vector3 v3, Color color)`

    Draw a color-filled triangle (vertex in counter-clockwise order!)"""

def DrawTriangleStrip3D(points: intptr, pointCount: int, color: color32) -> None:
    """Wraps `void DrawTriangleStrip3D(const Vector3 * points, int pointCount, Color color)`

    Draw a triangle strip defined by points"""

def DrawCube(position: vec3, width: float, height: float, length: float, color: color32) -> None:
    """Wraps `void DrawCube(Vector3 position, float width, float height, float length, Color color)`

    Draw cube"""

def DrawCubeV(position: vec3, size: vec3, color: color32) -> None:
    """Wraps `void DrawCubeV(Vector3 position, Vector3 size, Color color)`

    Draw cube (Vector version)"""

def DrawCubeWires(position: vec3, width: float, height: float, length: float, color: color32) -> None:
    """Wraps `void DrawCubeWires(Vector3 position, float width, float height, float length, Color color)`

    Draw cube wires"""

def DrawCubeWiresV(position: vec3, size: vec3, color: color32) -> None:
    """Wraps `void DrawCubeWiresV(Vector3 position, Vector3 size, Color color)`

    Draw cube wires (Vector version)"""

def DrawSphere(centerPos: vec3, radius: float, color: color32) -> None:
    """Wraps `void DrawSphere(Vector3 centerPos, float radius, Color color)`

    Draw sphere"""

def DrawSphereEx(centerPos: vec3, radius: float, rings: int, slices: int, color: color32) -> None:
    """Wraps `void DrawSphereEx(Vector3 centerPos, float radius, int rings, int slices, Color color)`

    Draw sphere with extended parameters"""

def DrawSphereWires(centerPos: vec3, radius: float, rings: int, slices: int, color: color32) -> None:
    """Wraps `void DrawSphereWires(Vector3 centerPos, float radius, int rings, int slices, Color color)`

    Draw sphere wires"""

def DrawCylinder(position: vec3, radiusTop: float, radiusBottom: float, height: float, slices: int, color: color32) -> None:
    """Wraps `void DrawCylinder(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color)`

    Draw a cylinder/cone"""

def DrawCylinderEx(startPos: vec3, endPos: vec3, startRadius: float, endRadius: float, sides: int, color: color32) -> None:
    """Wraps `void DrawCylinderEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color)`

    Draw a cylinder with base at startPos and top at endPos"""

def DrawCylinderWires(position: vec3, radiusTop: float, radiusBottom: float, height: float, slices: int, color: color32) -> None:
    """Wraps `void DrawCylinderWires(Vector3 position, float radiusTop, float radiusBottom, float height, int slices, Color color)`

    Draw a cylinder/cone wires"""

def DrawCylinderWiresEx(startPos: vec3, endPos: vec3, startRadius: float, endRadius: float, sides: int, color: color32) -> None:
    """Wraps `void DrawCylinderWiresEx(Vector3 startPos, Vector3 endPos, float startRadius, float endRadius, int sides, Color color)`

    Draw a cylinder wires with base at startPos and top at endPos"""

def DrawCapsule(startPos: vec3, endPos: vec3, radius: float, slices: int, rings: int, color: color32) -> None:
    """Wraps `void DrawCapsule(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color)`

    Draw a capsule with the center of its sphere caps at startPos and endPos"""

def DrawCapsuleWires(startPos: vec3, endPos: vec3, radius: float, slices: int, rings: int, color: color32) -> None:
    """Wraps `void DrawCapsuleWires(Vector3 startPos, Vector3 endPos, float radius, int slices, int rings, Color color)`

    Draw capsule wireframe with the center of its sphere caps at startPos and endPos"""

def DrawPlane(centerPos: vec3, size: vec2, color: color32) -> None:
    """Wraps `void DrawPlane(Vector3 centerPos, Vector2 size, Color color)`

    Draw a plane XZ"""

def DrawRay(ray: Ray, color: color32) -> None:
    """Wraps `void DrawRay(Ray ray, Color color)`

    Draw a ray line"""

def DrawGrid(slices: int, spacing: float) -> None:
    """Wraps `void DrawGrid(int slices, float spacing)`

    Draw a grid (centered at (0, 0, 0))"""

def LoadModel(fileName: str) -> Model:
    """Wraps `Model LoadModel(const char * fileName)`

    Load model from files (meshes and materials)"""

def LoadModelFromMesh(mesh: Mesh) -> Model:
    """Wraps `Model LoadModelFromMesh(Mesh mesh)`

    Load model from generated mesh (default material)"""

def IsModelValid(model: Model) -> bool:
    """Wraps `bool IsModelValid(Model model)`

    Check if a model is valid (loaded in GPU, VAO/VBOs)"""

def UnloadModel(model: Model) -> None:
    """Wraps `void UnloadModel(Model model)`

    Unload model (including meshes) from memory (RAM and/or VRAM)"""

def GetModelBoundingBox(model: Model) -> BoundingBox:
    """Wraps `BoundingBox GetModelBoundingBox(Model model)`

    Compute model bounding box limits (considers all meshes)"""

def DrawModel(model: Model, position: vec3, scale: float, tint: color32) -> None:
    """Wraps `void DrawModel(Model model, Vector3 position, float scale, Color tint)`

    Draw a model (with texture if set)"""

def DrawModelEx(model: Model, position: vec3, rotationAxis: vec3, rotationAngle: float, scale: vec3, tint: color32) -> None:
    """Wraps `void DrawModelEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)`

    Draw a model with extended parameters"""

def DrawModelWires(model: Model, position: vec3, scale: float, tint: color32) -> None:
    """Wraps `void DrawModelWires(Model model, Vector3 position, float scale, Color tint)`

    Draw a model wires (with texture if set)"""

def DrawModelWiresEx(model: Model, position: vec3, rotationAxis: vec3, rotationAngle: float, scale: vec3, tint: color32) -> None:
    """Wraps `void DrawModelWiresEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)`

    Draw a model wires (with texture if set) with extended parameters"""

def DrawModelPoints(model: Model, position: vec3, scale: float, tint: color32) -> None:
    """Wraps `void DrawModelPoints(Model model, Vector3 position, float scale, Color tint)`

    Draw a model as points"""

def DrawModelPointsEx(model: Model, position: vec3, rotationAxis: vec3, rotationAngle: float, scale: vec3, tint: color32) -> None:
    """Wraps `void DrawModelPointsEx(Model model, Vector3 position, Vector3 rotationAxis, float rotationAngle, Vector3 scale, Color tint)`

    Draw a model as points with extended parameters"""

def DrawBoundingBox(box: BoundingBox, color: color32) -> None:
    """Wraps `void DrawBoundingBox(BoundingBox box, Color color)`

    Draw bounding box (wires)"""

def DrawBillboard(camera: Camera, texture: Texture2D, position: vec3, scale: float, tint: color32) -> None:
    """Wraps `void DrawBillboard(Camera camera, Texture2D texture, Vector3 position, float scale, Color tint)`

    Draw a billboard texture"""

def DrawBillboardRec(camera: Camera, texture: Texture2D, source: Rectangle, position: vec3, size: vec2, tint: color32) -> None:
    """Wraps `void DrawBillboardRec(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector2 size, Color tint)`

    Draw a billboard texture defined by source"""

def DrawBillboardPro(camera: Camera, texture: Texture2D, source: Rectangle, position: vec3, up: vec3, size: vec2, origin: vec2, rotation: float, tint: color32) -> None:
    """Wraps `void DrawBillboardPro(Camera camera, Texture2D texture, Rectangle source, Vector3 position, Vector3 up, Vector2 size, Vector2 origin, float rotation, Color tint)`

    Draw a billboard texture defined by source and rotation"""

def UploadMesh(mesh: intptr, dynamic: bool) -> None:
    """Wraps `void UploadMesh(Mesh * mesh, bool dynamic)`

    Upload mesh vertex data in GPU and provide VAO/VBO ids"""

def UpdateMeshBuffer(mesh: Mesh, index: int, data: intptr, dataSize: int, offset: int) -> None:
    """Wraps `void UpdateMeshBuffer(Mesh mesh, int index, const void * data, int dataSize, int offset)`

    Update mesh vertex data in GPU for a specific buffer index"""

def UnloadMesh(mesh: Mesh) -> None:
    """Wraps `void UnloadMesh(Mesh mesh)`

    Unload mesh data from CPU and GPU"""

def DrawMesh(mesh: Mesh, material: Material, transform: Matrix) -> None:
    """Wraps `void DrawMesh(Mesh mesh, Material material, Matrix transform)`

    Draw a 3d mesh with material and transform"""

def DrawMeshInstanced(mesh: Mesh, material: Material, transforms: intptr, instances: int) -> None:
    """Wraps `void DrawMeshInstanced(Mesh mesh, Material material, const Matrix * transforms, int instances)`

    Draw multiple mesh instances with material and different transforms"""

def GetMeshBoundingBox(mesh: Mesh) -> BoundingBox:
    """Wraps `BoundingBox GetMeshBoundingBox(Mesh mesh)`

    Compute mesh bounding box limits"""

def GenMeshTangents(mesh: intptr) -> None:
    """Wraps `void GenMeshTangents(Mesh * mesh)`

    Compute mesh tangents"""

def ExportMesh(mesh: Mesh, fileName: str) -> bool:
    """Wraps `bool ExportMesh(Mesh mesh, const char * fileName)`

    Export mesh data to file, returns true on success"""

def ExportMeshAsCode(mesh: Mesh, fileName: str) -> bool:
    """Wraps `bool ExportMeshAsCode(Mesh mesh, const char * fileName)`

    Export mesh as code file (.h) defining multiple arrays of vertex attributes"""

def GenMeshPoly(sides: int, radius: float) -> Mesh:
    """Wraps `Mesh GenMeshPoly(int sides, float radius)`

    Generate polygonal mesh"""

def GenMeshPlane(width: float, length: float, resX: int, resZ: int) -> Mesh:
    """Wraps `Mesh GenMeshPlane(float width, float length, int resX, int resZ)`

    Generate plane mesh (with subdivisions)"""

def GenMeshCube(width: float, height: float, length: float) -> Mesh:
    """Wraps `Mesh GenMeshCube(float width, float height, float length)`

    Generate cuboid mesh"""

def GenMeshSphere(radius: float, rings: int, slices: int) -> Mesh:
    """Wraps `Mesh GenMeshSphere(float radius, int rings, int slices)`

    Generate sphere mesh (standard sphere)"""

def GenMeshHemiSphere(radius: float, rings: int, slices: int) -> Mesh:
    """Wraps `Mesh GenMeshHemiSphere(float radius, int rings, int slices)`

    Generate half-sphere mesh (no bottom cap)"""

def GenMeshCylinder(radius: float, height: float, slices: int) -> Mesh:
    """Wraps `Mesh GenMeshCylinder(float radius, float height, int slices)`

    Generate cylinder mesh"""

def GenMeshCone(radius: float, height: float, slices: int) -> Mesh:
    """Wraps `Mesh GenMeshCone(float radius, float height, int slices)`

    Generate cone/pyramid mesh"""

def GenMeshTorus(radius: float, size: float, radSeg: int, sides: int) -> Mesh:
    """Wraps `Mesh GenMeshTorus(float radius, float size, int radSeg, int sides)`

    Generate torus mesh"""

def GenMeshKnot(radius: float, size: float, radSeg: int, sides: int) -> Mesh:
    """Wraps `Mesh GenMeshKnot(float radius, float size, int radSeg, int sides)`

    Generate trefoil knot mesh"""

def GenMeshHeightmap(heightmap: Image, size: vec3) -> Mesh:
    """Wraps `Mesh GenMeshHeightmap(Image heightmap, Vector3 size)`

    Generate heightmap mesh from image data"""

def GenMeshCubicmap(cubicmap: Image, cubeSize: vec3) -> Mesh:
    """Wraps `Mesh GenMeshCubicmap(Image cubicmap, Vector3 cubeSize)`

    Generate cubes-based map mesh from image data"""

def LoadMaterials(fileName: str, materialCount: intptr) -> intptr:
    """Wraps `Material * LoadMaterials(const char * fileName, int * materialCount)`

    Load materials from model file"""

def LoadMaterialDefault() -> Material:
    """Wraps `Material LoadMaterialDefault()`

    Load default material (Supports: DIFFUSE, SPECULAR, NORMAL maps)"""

def IsMaterialValid(material: Material) -> bool:
    """Wraps `bool IsMaterialValid(Material material)`

    Check if a material is valid (shader assigned, map textures loaded in GPU)"""

def UnloadMaterial(material: Material) -> None:
    """Wraps `void UnloadMaterial(Material material)`

    Unload material from GPU memory (VRAM)"""

def SetMaterialTexture(material: intptr, mapType: int, texture: Texture2D) -> None:
    """Wraps `void SetMaterialTexture(Material * material, int mapType, Texture2D texture)`

    Set texture for a material map type (MATERIAL_MAP_DIFFUSE, MATERIAL_MAP_SPECULAR...)"""

def SetModelMeshMaterial(model: intptr, meshId: int, materialId: int) -> None:
    """Wraps `void SetModelMeshMaterial(Model * model, int meshId, int materialId)`

    Set material for a mesh"""

def LoadModelAnimations(fileName: str, animCount: intptr) -> intptr:
    """Wraps `ModelAnimation * LoadModelAnimations(const char * fileName, int * animCount)`

    Load model animations from file"""

def UpdateModelAnimation(model: Model, anim: ModelAnimation, frame: int) -> None:
    """Wraps `void UpdateModelAnimation(Model model, ModelAnimation anim, int frame)`

    Update model animation pose (CPU)"""

def UpdateModelAnimationBones(model: Model, anim: ModelAnimation, frame: int) -> None:
    """Wraps `void UpdateModelAnimationBones(Model model, ModelAnimation anim, int frame)`

    Update model animation mesh bone matrices (GPU skinning)"""

def UnloadModelAnimation(anim: ModelAnimation) -> None:
    """Wraps `void UnloadModelAnimation(ModelAnimation anim)`

    Unload animation data"""

def UnloadModelAnimations(animations: intptr, animCount: int) -> None:
    """Wraps `void UnloadModelAnimations(ModelAnimation * animations, int animCount)`

    Unload animation array data"""

def IsModelAnimationValid(model: Model, anim: ModelAnimation) -> bool:
    """Wraps `bool IsModelAnimationValid(Model model, ModelAnimation anim)`

    Check model animation skeleton match"""

def CheckCollisionSpheres(center1: vec3, radius1: float, center2: vec3, radius2: float) -> bool:
    """Wraps `bool CheckCollisionSpheres(Vector3 center1, float radius1, Vector3 center2, float radius2)`

    Check collision between two spheres"""

def CheckCollisionBoxes(box1: BoundingBox, box2: BoundingBox) -> bool:
    """Wraps `bool CheckCollisionBoxes(BoundingBox box1, BoundingBox box2)`

    Check collision between two bounding boxes"""

def CheckCollisionBoxSphere(box: BoundingBox, center: vec3, radius: float) -> bool:
    """Wraps `bool CheckCollisionBoxSphere(BoundingBox box, Vector3 center, float radius)`

    Check collision between box and sphere"""

def GetRayCollisionSphere(ray: Ray, center: vec3, radius: float) -> RayCollision:
    """Wraps `RayCollision GetRayCollisionSphere(Ray ray, Vector3 center, float radius)`

    Get collision info between ray and sphere"""

def GetRayCollisionBox(ray: Ray, box: BoundingBox) -> RayCollision:
    """Wraps `RayCollision GetRayCollisionBox(Ray ray, BoundingBox box)`

    Get collision info between ray and box"""

def GetRayCollisionMesh(ray: Ray, mesh: Mesh, transform: Matrix) -> RayCollision:
    """Wraps `RayCollision GetRayCollisionMesh(Ray ray, Mesh mesh, Matrix transform)`

    Get collision info between ray and mesh"""

def GetRayCollisionTriangle(ray: Ray, p1: vec3, p2: vec3, p3: vec3) -> RayCollision:
    """Wraps `RayCollision GetRayCollisionTriangle(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3)`

    Get collision info between ray and triangle"""

def GetRayCollisionQuad(ray: Ray, p1: vec3, p2: vec3, p3: vec3, p4: vec3) -> RayCollision:
    """Wraps `RayCollision GetRayCollisionQuad(Ray ray, Vector3 p1, Vector3 p2, Vector3 p3, Vector3 p4)`

    Get collision info between ray and quad"""

def InitAudioDevice() -> None:
    """Wraps `void InitAudioDevice()`

    Initialize audio device and context"""

def CloseAudioDevice() -> None:
    """Wraps `void CloseAudioDevice()`

    Close the audio device and context"""

def IsAudioDeviceReady() -> bool:
    """Wraps `bool IsAudioDeviceReady()`

    Check if audio device has been initialized successfully"""

def SetMasterVolume(volume: float) -> None:
    """Wraps `void SetMasterVolume(float volume)`

    Set master volume (listener)"""

def GetMasterVolume() -> float:
    """Wraps `float GetMasterVolume()`

    Get master volume (listener)"""

def LoadWave(fileName: str) -> Wave:
    """Wraps `Wave LoadWave(const char * fileName)`

    Load wave data from file"""

def LoadWaveFromMemory(fileType: str, fileData: intptr, dataSize: int) -> Wave:
    """Wraps `Wave LoadWaveFromMemory(const char * fileType, const unsigned char * fileData, int dataSize)`

    Load wave from memory buffer, fileType refers to extension: i.e. '.wav'"""

def IsWaveValid(wave: Wave) -> bool:
    """Wraps `bool IsWaveValid(Wave wave)`

    Checks if wave data is valid (data loaded and parameters)"""

def LoadSound(fileName: str) -> Sound:
    """Wraps `Sound LoadSound(const char * fileName)`

    Load sound from file"""

def LoadSoundFromWave(wave: Wave) -> Sound:
    """Wraps `Sound LoadSoundFromWave(Wave wave)`

    Load sound from wave data"""

def LoadSoundAlias(source: Sound) -> Sound:
    """Wraps `Sound LoadSoundAlias(Sound source)`

    Create a new sound that shares the same sample data as the source sound, does not own the sound data"""

def IsSoundValid(sound: Sound) -> bool:
    """Wraps `bool IsSoundValid(Sound sound)`

    Checks if a sound is valid (data loaded and buffers initialized)"""

def UpdateSound(sound: Sound, data: intptr, sampleCount: int) -> None:
    """Wraps `void UpdateSound(Sound sound, const void * data, int sampleCount)`

    Update sound buffer with new data"""

def UnloadWave(wave: Wave) -> None:
    """Wraps `void UnloadWave(Wave wave)`

    Unload wave data"""

def UnloadSound(sound: Sound) -> None:
    """Wraps `void UnloadSound(Sound sound)`

    Unload sound"""

def UnloadSoundAlias(alias: Sound) -> None:
    """Wraps `void UnloadSoundAlias(Sound alias)`

    Unload a sound alias (does not deallocate sample data)"""

def ExportWave(wave: Wave, fileName: str) -> bool:
    """Wraps `bool ExportWave(Wave wave, const char * fileName)`

    Export wave data to file, returns true on success"""

def ExportWaveAsCode(wave: Wave, fileName: str) -> bool:
    """Wraps `bool ExportWaveAsCode(Wave wave, const char * fileName)`

    Export wave sample data to code (.h), returns true on success"""

def PlaySound(sound: Sound) -> None:
    """Wraps `void PlaySound(Sound sound)`

    Play a sound"""

def StopSound(sound: Sound) -> None:
    """Wraps `void StopSound(Sound sound)`

    Stop playing a sound"""

def PauseSound(sound: Sound) -> None:
    """Wraps `void PauseSound(Sound sound)`

    Pause a sound"""

def ResumeSound(sound: Sound) -> None:
    """Wraps `void ResumeSound(Sound sound)`

    Resume a paused sound"""

def IsSoundPlaying(sound: Sound) -> bool:
    """Wraps `bool IsSoundPlaying(Sound sound)`

    Check if a sound is currently playing"""

def SetSoundVolume(sound: Sound, volume: float) -> None:
    """Wraps `void SetSoundVolume(Sound sound, float volume)`

    Set volume for a sound (1.0 is max level)"""

def SetSoundPitch(sound: Sound, pitch: float) -> None:
    """Wraps `void SetSoundPitch(Sound sound, float pitch)`

    Set pitch for a sound (1.0 is base level)"""

def SetSoundPan(sound: Sound, pan: float) -> None:
    """Wraps `void SetSoundPan(Sound sound, float pan)`

    Set pan for a sound (0.5 is center)"""

def WaveCopy(wave: Wave) -> Wave:
    """Wraps `Wave WaveCopy(Wave wave)`

    Copy a wave to a new wave"""

def WaveCrop(wave: intptr, initFrame: int, finalFrame: int) -> None:
    """Wraps `void WaveCrop(Wave * wave, int initFrame, int finalFrame)`

    Crop a wave to defined frames range"""

def WaveFormat(wave: intptr, sampleRate: int, sampleSize: int, channels: int) -> None:
    """Wraps `void WaveFormat(Wave * wave, int sampleRate, int sampleSize, int channels)`

    Convert wave data to desired format"""

def LoadWaveSamples(wave: Wave) -> intptr:
    """Wraps `float * LoadWaveSamples(Wave wave)`

    Load samples data from wave as a 32bit float data array"""

def UnloadWaveSamples(samples: intptr) -> None:
    """Wraps `void UnloadWaveSamples(float * samples)`

    Unload samples data loaded with LoadWaveSamples()"""

def LoadMusicStream(fileName: str) -> Music:
    """Wraps `Music LoadMusicStream(const char * fileName)`

    Load music stream from file"""

def LoadMusicStreamFromMemory(fileType: str, data: intptr, dataSize: int) -> Music:
    """Wraps `Music LoadMusicStreamFromMemory(const char * fileType, const unsigned char * data, int dataSize)`

    Load music stream from data"""

def IsMusicValid(music: Music) -> bool:
    """Wraps `bool IsMusicValid(Music music)`

    Checks if a music stream is valid (context and buffers initialized)"""

def UnloadMusicStream(music: Music) -> None:
    """Wraps `void UnloadMusicStream(Music music)`

    Unload music stream"""

def PlayMusicStream(music: Music) -> None:
    """Wraps `void PlayMusicStream(Music music)`

    Start music playing"""

def IsMusicStreamPlaying(music: Music) -> bool:
    """Wraps `bool IsMusicStreamPlaying(Music music)`

    Check if music is playing"""

def UpdateMusicStream(music: Music) -> None:
    """Wraps `void UpdateMusicStream(Music music)`

    Updates buffers for music streaming"""

def StopMusicStream(music: Music) -> None:
    """Wraps `void StopMusicStream(Music music)`

    Stop music playing"""

def PauseMusicStream(music: Music) -> None:
    """Wraps `void PauseMusicStream(Music music)`

    Pause music playing"""

def ResumeMusicStream(music: Music) -> None:
    """Wraps `void ResumeMusicStream(Music music)`

    Resume playing paused music"""

def SeekMusicStream(music: Music, position: float) -> None:
    """Wraps `void SeekMusicStream(Music music, float position)`

    Seek music to a position (in seconds)"""

def SetMusicVolume(music: Music, volume: float) -> None:
    """Wraps `void SetMusicVolume(Music music, float volume)`

    Set volume for music (1.0 is max level)"""

def SetMusicPitch(music: Music, pitch: float) -> None:
    """Wraps `void SetMusicPitch(Music music, float pitch)`

    Set pitch for a music (1.0 is base level)"""

def SetMusicPan(music: Music, pan: float) -> None:
    """Wraps `void SetMusicPan(Music music, float pan)`

    Set pan for a music (0.5 is center)"""

def GetMusicTimeLength(music: Music) -> float:
    """Wraps `float GetMusicTimeLength(Music music)`

    Get music time length (in seconds)"""

def GetMusicTimePlayed(music: Music) -> float:
    """Wraps `float GetMusicTimePlayed(Music music)`

    Get current music time played (in seconds)"""

def LoadAudioStream(sampleRate: int, sampleSize: int, channels: int) -> AudioStream:
    """Wraps `AudioStream LoadAudioStream(unsigned int sampleRate, unsigned int sampleSize, unsigned int channels)`

    Load audio stream (to stream raw audio pcm data)"""

def IsAudioStreamValid(stream: AudioStream) -> bool:
    """Wraps `bool IsAudioStreamValid(AudioStream stream)`

    Checks if an audio stream is valid (buffers initialized)"""

def UnloadAudioStream(stream: AudioStream) -> None:
    """Wraps `void UnloadAudioStream(AudioStream stream)`

    Unload audio stream and free memory"""

def UpdateAudioStream(stream: AudioStream, data: intptr, frameCount: int) -> None:
    """Wraps `void UpdateAudioStream(AudioStream stream, const void * data, int frameCount)`

    Update audio stream buffers with data"""

def IsAudioStreamProcessed(stream: AudioStream) -> bool:
    """Wraps `bool IsAudioStreamProcessed(AudioStream stream)`

    Check if any audio stream buffers requires refill"""

def PlayAudioStream(stream: AudioStream) -> None:
    """Wraps `void PlayAudioStream(AudioStream stream)`

    Play audio stream"""

def PauseAudioStream(stream: AudioStream) -> None:
    """Wraps `void PauseAudioStream(AudioStream stream)`

    Pause audio stream"""

def ResumeAudioStream(stream: AudioStream) -> None:
    """Wraps `void ResumeAudioStream(AudioStream stream)`

    Resume audio stream"""

def IsAudioStreamPlaying(stream: AudioStream) -> bool:
    """Wraps `bool IsAudioStreamPlaying(AudioStream stream)`

    Check if audio stream is playing"""

def StopAudioStream(stream: AudioStream) -> None:
    """Wraps `void StopAudioStream(AudioStream stream)`

    Stop audio stream"""

def SetAudioStreamVolume(stream: AudioStream, volume: float) -> None:
    """Wraps `void SetAudioStreamVolume(AudioStream stream, float volume)`

    Set volume for audio stream (1.0 is max level)"""

def SetAudioStreamPitch(stream: AudioStream, pitch: float) -> None:
    """Wraps `void SetAudioStreamPitch(AudioStream stream, float pitch)`

    Set pitch for audio stream (1.0 is base level)"""

def SetAudioStreamPan(stream: AudioStream, pan: float) -> None:
    """Wraps `void SetAudioStreamPan(AudioStream stream, float pan)`

    Set pan for audio stream (0.5 is centered)"""

def SetAudioStreamBufferSizeDefault(size: int) -> None:
    """Wraps `void SetAudioStreamBufferSizeDefault(int size)`

    Default size for new audio streams"""

# aliases
Quaternion = Vector4
Texture2D = Texture
TextureCubemap = Texture
RenderTexture2D = RenderTexture
Camera = Camera3D
# enums
FLAG_VSYNC_HINT: int = 64
FLAG_FULLSCREEN_MODE: int = 2
FLAG_WINDOW_RESIZABLE: int = 4
FLAG_WINDOW_UNDECORATED: int = 8
FLAG_WINDOW_HIDDEN: int = 128
FLAG_WINDOW_MINIMIZED: int = 512
FLAG_WINDOW_MAXIMIZED: int = 1024
FLAG_WINDOW_UNFOCUSED: int = 2048
FLAG_WINDOW_TOPMOST: int = 4096
FLAG_WINDOW_ALWAYS_RUN: int = 256
FLAG_WINDOW_TRANSPARENT: int = 16
FLAG_WINDOW_HIGHDPI: int = 8192
FLAG_WINDOW_MOUSE_PASSTHROUGH: int = 16384
FLAG_BORDERLESS_WINDOWED_MODE: int = 32768
FLAG_MSAA_4X_HINT: int = 32
FLAG_INTERLACED_HINT: int = 65536
LOG_ALL: int = 0
LOG_TRACE: int = 1
LOG_DEBUG: int = 2
LOG_INFO: int = 3
LOG_WARNING: int = 4
LOG_ERROR: int = 5
LOG_FATAL: int = 6
LOG_NONE: int = 7
KEY_NULL: int = 0
KEY_APOSTROPHE: int = 39
KEY_COMMA: int = 44
KEY_MINUS: int = 45
KEY_PERIOD: int = 46
KEY_SLASH: int = 47
KEY_ZERO: int = 48
KEY_ONE: int = 49
KEY_TWO: int = 50
KEY_THREE: int = 51
KEY_FOUR: int = 52
KEY_FIVE: int = 53
KEY_SIX: int = 54
KEY_SEVEN: int = 55
KEY_EIGHT: int = 56
KEY_NINE: int = 57
KEY_SEMICOLON: int = 59
KEY_EQUAL: int = 61
KEY_A: int = 65
KEY_B: int = 66
KEY_C: int = 67
KEY_D: int = 68
KEY_E: int = 69
KEY_F: int = 70
KEY_G: int = 71
KEY_H: int = 72
KEY_I: int = 73
KEY_J: int = 74
KEY_K: int = 75
KEY_L: int = 76
KEY_M: int = 77
KEY_N: int = 78
KEY_O: int = 79
KEY_P: int = 80
KEY_Q: int = 81
KEY_R: int = 82
KEY_S: int = 83
KEY_T: int = 84
KEY_U: int = 85
KEY_V: int = 86
KEY_W: int = 87
KEY_X: int = 88
KEY_Y: int = 89
KEY_Z: int = 90
KEY_LEFT_BRACKET: int = 91
KEY_BACKSLASH: int = 92
KEY_RIGHT_BRACKET: int = 93
KEY_GRAVE: int = 96
KEY_SPACE: int = 32
KEY_ESCAPE: int = 256
KEY_ENTER: int = 257
KEY_TAB: int = 258
KEY_BACKSPACE: int = 259
KEY_INSERT: int = 260
KEY_DELETE: int = 261
KEY_RIGHT: int = 262
KEY_LEFT: int = 263
KEY_DOWN: int = 264
KEY_UP: int = 265
KEY_PAGE_UP: int = 266
KEY_PAGE_DOWN: int = 267
KEY_HOME: int = 268
KEY_END: int = 269
KEY_CAPS_LOCK: int = 280
KEY_SCROLL_LOCK: int = 281
KEY_NUM_LOCK: int = 282
KEY_PRINT_SCREEN: int = 283
KEY_PAUSE: int = 284
KEY_F1: int = 290
KEY_F2: int = 291
KEY_F3: int = 292
KEY_F4: int = 293
KEY_F5: int = 294
KEY_F6: int = 295
KEY_F7: int = 296
KEY_F8: int = 297
KEY_F9: int = 298
KEY_F10: int = 299
KEY_F11: int = 300
KEY_F12: int = 301
KEY_LEFT_SHIFT: int = 340
KEY_LEFT_CONTROL: int = 341
KEY_LEFT_ALT: int = 342
KEY_LEFT_SUPER: int = 343
KEY_RIGHT_SHIFT: int = 344
KEY_RIGHT_CONTROL: int = 345
KEY_RIGHT_ALT: int = 346
KEY_RIGHT_SUPER: int = 347
KEY_KB_MENU: int = 348
KEY_KP_0: int = 320
KEY_KP_1: int = 321
KEY_KP_2: int = 322
KEY_KP_3: int = 323
KEY_KP_4: int = 324
KEY_KP_5: int = 325
KEY_KP_6: int = 326
KEY_KP_7: int = 327
KEY_KP_8: int = 328
KEY_KP_9: int = 329
KEY_KP_DECIMAL: int = 330
KEY_KP_DIVIDE: int = 331
KEY_KP_MULTIPLY: int = 332
KEY_KP_SUBTRACT: int = 333
KEY_KP_ADD: int = 334
KEY_KP_ENTER: int = 335
KEY_KP_EQUAL: int = 336
KEY_BACK: int = 4
KEY_MENU: int = 5
KEY_VOLUME_UP: int = 24
KEY_VOLUME_DOWN: int = 25
MOUSE_BUTTON_LEFT: int = 0
MOUSE_BUTTON_RIGHT: int = 1
MOUSE_BUTTON_MIDDLE: int = 2
MOUSE_BUTTON_SIDE: int = 3
MOUSE_BUTTON_EXTRA: int = 4
MOUSE_BUTTON_FORWARD: int = 5
MOUSE_BUTTON_BACK: int = 6
MOUSE_CURSOR_DEFAULT: int = 0
MOUSE_CURSOR_ARROW: int = 1
MOUSE_CURSOR_IBEAM: int = 2
MOUSE_CURSOR_CROSSHAIR: int = 3
MOUSE_CURSOR_POINTING_HAND: int = 4
MOUSE_CURSOR_RESIZE_EW: int = 5
MOUSE_CURSOR_RESIZE_NS: int = 6
MOUSE_CURSOR_RESIZE_NWSE: int = 7
MOUSE_CURSOR_RESIZE_NESW: int = 8
MOUSE_CURSOR_RESIZE_ALL: int = 9
MOUSE_CURSOR_NOT_ALLOWED: int = 10
GAMEPAD_BUTTON_UNKNOWN: int = 0
GAMEPAD_BUTTON_LEFT_FACE_UP: int = 1
GAMEPAD_BUTTON_LEFT_FACE_RIGHT: int = 2
GAMEPAD_BUTTON_LEFT_FACE_DOWN: int = 3
GAMEPAD_BUTTON_LEFT_FACE_LEFT: int = 4
GAMEPAD_BUTTON_RIGHT_FACE_UP: int = 5
GAMEPAD_BUTTON_RIGHT_FACE_RIGHT: int = 6
GAMEPAD_BUTTON_RIGHT_FACE_DOWN: int = 7
GAMEPAD_BUTTON_RIGHT_FACE_LEFT: int = 8
GAMEPAD_BUTTON_LEFT_TRIGGER_1: int = 9
GAMEPAD_BUTTON_LEFT_TRIGGER_2: int = 10
GAMEPAD_BUTTON_RIGHT_TRIGGER_1: int = 11
GAMEPAD_BUTTON_RIGHT_TRIGGER_2: int = 12
GAMEPAD_BUTTON_MIDDLE_LEFT: int = 13
GAMEPAD_BUTTON_MIDDLE: int = 14
GAMEPAD_BUTTON_MIDDLE_RIGHT: int = 15
GAMEPAD_BUTTON_LEFT_THUMB: int = 16
GAMEPAD_BUTTON_RIGHT_THUMB: int = 17
GAMEPAD_AXIS_LEFT_X: int = 0
GAMEPAD_AXIS_LEFT_Y: int = 1
GAMEPAD_AXIS_RIGHT_X: int = 2
GAMEPAD_AXIS_RIGHT_Y: int = 3
GAMEPAD_AXIS_LEFT_TRIGGER: int = 4
GAMEPAD_AXIS_RIGHT_TRIGGER: int = 5
MATERIAL_MAP_ALBEDO: int = 0
MATERIAL_MAP_METALNESS: int = 1
MATERIAL_MAP_NORMAL: int = 2
MATERIAL_MAP_ROUGHNESS: int = 3
MATERIAL_MAP_OCCLUSION: int = 4
MATERIAL_MAP_EMISSION: int = 5
MATERIAL_MAP_HEIGHT: int = 6
MATERIAL_MAP_CUBEMAP: int = 7
MATERIAL_MAP_IRRADIANCE: int = 8
MATERIAL_MAP_PREFILTER: int = 9
MATERIAL_MAP_BRDF: int = 10
SHADER_LOC_VERTEX_POSITION: int = 0
SHADER_LOC_VERTEX_TEXCOORD01: int = 1
SHADER_LOC_VERTEX_TEXCOORD02: int = 2
SHADER_LOC_VERTEX_NORMAL: int = 3
SHADER_LOC_VERTEX_TANGENT: int = 4
SHADER_LOC_VERTEX_COLOR: int = 5
SHADER_LOC_MATRIX_MVP: int = 6
SHADER_LOC_MATRIX_VIEW: int = 7
SHADER_LOC_MATRIX_PROJECTION: int = 8
SHADER_LOC_MATRIX_MODEL: int = 9
SHADER_LOC_MATRIX_NORMAL: int = 10
SHADER_LOC_VECTOR_VIEW: int = 11
SHADER_LOC_COLOR_DIFFUSE: int = 12
SHADER_LOC_COLOR_SPECULAR: int = 13
SHADER_LOC_COLOR_AMBIENT: int = 14
SHADER_LOC_MAP_ALBEDO: int = 15
SHADER_LOC_MAP_METALNESS: int = 16
SHADER_LOC_MAP_NORMAL: int = 17
SHADER_LOC_MAP_ROUGHNESS: int = 18
SHADER_LOC_MAP_OCCLUSION: int = 19
SHADER_LOC_MAP_EMISSION: int = 20
SHADER_LOC_MAP_HEIGHT: int = 21
SHADER_LOC_MAP_CUBEMAP: int = 22
SHADER_LOC_MAP_IRRADIANCE: int = 23
SHADER_LOC_MAP_PREFILTER: int = 24
SHADER_LOC_MAP_BRDF: int = 25
SHADER_LOC_VERTEX_BONEIDS: int = 26
SHADER_LOC_VERTEX_BONEWEIGHTS: int = 27
SHADER_LOC_BONE_MATRICES: int = 28
SHADER_UNIFORM_FLOAT: int = 0
SHADER_UNIFORM_VEC2: int = 1
SHADER_UNIFORM_VEC3: int = 2
SHADER_UNIFORM_VEC4: int = 3
SHADER_UNIFORM_INT: int = 4
SHADER_UNIFORM_IVEC2: int = 5
SHADER_UNIFORM_IVEC3: int = 6
SHADER_UNIFORM_IVEC4: int = 7
SHADER_UNIFORM_SAMPLER2D: int = 8
SHADER_ATTRIB_FLOAT: int = 0
SHADER_ATTRIB_VEC2: int = 1
SHADER_ATTRIB_VEC3: int = 2
SHADER_ATTRIB_VEC4: int = 3
PIXELFORMAT_UNCOMPRESSED_GRAYSCALE: int = 1
PIXELFORMAT_UNCOMPRESSED_GRAY_ALPHA: int = 2
PIXELFORMAT_UNCOMPRESSED_R5G6B5: int = 3
PIXELFORMAT_UNCOMPRESSED_R8G8B8: int = 4
PIXELFORMAT_UNCOMPRESSED_R5G5B5A1: int = 5
PIXELFORMAT_UNCOMPRESSED_R4G4B4A4: int = 6
PIXELFORMAT_UNCOMPRESSED_R8G8B8A8: int = 7
PIXELFORMAT_UNCOMPRESSED_R32: int = 8
PIXELFORMAT_UNCOMPRESSED_R32G32B32: int = 9
PIXELFORMAT_UNCOMPRESSED_R32G32B32A32: int = 10
PIXELFORMAT_UNCOMPRESSED_R16: int = 11
PIXELFORMAT_UNCOMPRESSED_R16G16B16: int = 12
PIXELFORMAT_UNCOMPRESSED_R16G16B16A16: int = 13
PIXELFORMAT_COMPRESSED_DXT1_RGB: int = 14
PIXELFORMAT_COMPRESSED_DXT1_RGBA: int = 15
PIXELFORMAT_COMPRESSED_DXT3_RGBA: int = 16
PIXELFORMAT_COMPRESSED_DXT5_RGBA: int = 17
PIXELFORMAT_COMPRESSED_ETC1_RGB: int = 18
PIXELFORMAT_COMPRESSED_ETC2_RGB: int = 19
PIXELFORMAT_COMPRESSED_ETC2_EAC_RGBA: int = 20
PIXELFORMAT_COMPRESSED_PVRT_RGB: int = 21
PIXELFORMAT_COMPRESSED_PVRT_RGBA: int = 22
PIXELFORMAT_COMPRESSED_ASTC_4x4_RGBA: int = 23
PIXELFORMAT_COMPRESSED_ASTC_8x8_RGBA: int = 24
TEXTURE_FILTER_POINT: int = 0
TEXTURE_FILTER_BILINEAR: int = 1
TEXTURE_FILTER_TRILINEAR: int = 2
TEXTURE_FILTER_ANISOTROPIC_4X: int = 3
TEXTURE_FILTER_ANISOTROPIC_8X: int = 4
TEXTURE_FILTER_ANISOTROPIC_16X: int = 5
TEXTURE_WRAP_REPEAT: int = 0
TEXTURE_WRAP_CLAMP: int = 1
TEXTURE_WRAP_MIRROR_REPEAT: int = 2
TEXTURE_WRAP_MIRROR_CLAMP: int = 3
CUBEMAP_LAYOUT_AUTO_DETECT: int = 0
CUBEMAP_LAYOUT_LINE_VERTICAL: int = 1
CUBEMAP_LAYOUT_LINE_HORIZONTAL: int = 2
CUBEMAP_LAYOUT_CROSS_THREE_BY_FOUR: int = 3
CUBEMAP_LAYOUT_CROSS_FOUR_BY_THREE: int = 4
FONT_DEFAULT: int = 0
FONT_BITMAP: int = 1
FONT_SDF: int = 2
BLEND_ALPHA: int = 0
BLEND_ADDITIVE: int = 1
BLEND_MULTIPLIED: int = 2
BLEND_ADD_COLORS: int = 3
BLEND_SUBTRACT_COLORS: int = 4
BLEND_ALPHA_PREMULTIPLY: int = 5
BLEND_CUSTOM: int = 6
BLEND_CUSTOM_SEPARATE: int = 7
GESTURE_NONE: int = 0
GESTURE_TAP: int = 1
GESTURE_DOUBLETAP: int = 2
GESTURE_HOLD: int = 4
GESTURE_DRAG: int = 8
GESTURE_SWIPE_RIGHT: int = 16
GESTURE_SWIPE_LEFT: int = 32
GESTURE_SWIPE_UP: int = 64
GESTURE_SWIPE_DOWN: int = 128
GESTURE_PINCH_IN: int = 256
GESTURE_PINCH_OUT: int = 512
CAMERA_CUSTOM: int = 0
CAMERA_FREE: int = 1
CAMERA_ORBITAL: int = 2
CAMERA_FIRST_PERSON: int = 3
CAMERA_THIRD_PERSON: int = 4
CAMERA_PERSPECTIVE: int = 0
CAMERA_ORTHOGRAPHIC: int = 1
NPATCH_NINE_PATCH: int = 0
NPATCH_THREE_PATCH_VERTICAL: int = 1
NPATCH_THREE_PATCH_HORIZONTAL: int = 2