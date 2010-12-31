//
//  SemiSecretTexture.h
//  flixel-ios
//
//  Copyright Semi Secret Software 2009-2010. All rights reserved.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.
//

#import <Foundation/Foundation.h>
#import <OpenGLES/ES1/gl.h>

@class UIView;

typedef enum {
  SSTextureFilteringDefault,
  SSTextureFilteringNearest,
  SSTextureFilteringLinear,
} SSTextureFiltering;

typedef enum {
  SSTextureDepth32Bits,
  SSTextureDepth16Bits5551,
  SSTextureDepth16Bits4444,
} SSTextureDepth;

@interface SemiSecretTexture : NSObject <NSCopying>
{
  GLuint texture;
  CGSize size;
  CGSize paddedSize;
  CGPoint offset;
  SemiSecretTexture * atlasTexture;
  CGPoint atlasOffset;
  CGPoint atlasScale;
  GLshort vertexData[4*2];
  GLshort * texCoords;
  unsigned int frames;
  BOOL animated;
  GLubyte * data;
}
@property (nonatomic, readonly) GLuint texture;
@property (nonatomic, readonly) CGSize size;
@property (nonatomic, readonly) CGSize paddedSize;
@property (nonatomic, readonly) CGPoint offset;

@property (nonatomic, readonly) unsigned int width;
@property (nonatomic, readonly) unsigned int height;
@property (nonatomic, readonly) unsigned int paddedWidth;
@property (nonatomic, readonly) unsigned int paddedHeight;

@property (nonatomic, readonly) unsigned int frames;
@property (nonatomic, readonly) GLshort * vertices;
@property (nonatomic, readonly) GLshort * texCoords;
@property (nonatomic, assign) BOOL animated;

@property (nonatomic, readonly) SemiSecretTexture * atlasTexture;
@property (nonatomic, readonly) CGPoint atlasOffset;
@property (nonatomic, readonly) CGPoint atlasScale;

+ (void) setTextureFilteringMode:(SSTextureFiltering)filtering;
+ (SSTextureFiltering) textureFilteringMode;
+ (void) setTextureDepth:(SSTextureDepth)depth;
+ (SSTextureDepth) textureDepth;

+ (id) textureWithImage:(NSString *)filename;
+ (id) textureWithView:(UIView *)view;
+ (id) textureWithColor:(unsigned int)color;
+ (id) textureWithCGColor:(CGColorRef)cgcolor;
+ (id) textureWithSize:(CGSize)size images:(NSArray *)images locations:(NSDictionary *)locations;
+ (id) textureWithAtlasTexture:(SemiSecretTexture *)atlasTexture offset:(CGPoint)offset size:(CGSize)size;

- (id) initWithImage:(NSString *)filename;
- (id) initWithView:(UIView *)view;
- (id) initWithColor:(unsigned int)color;
- (id) initWithCGColor:(CGColorRef)cgcolor;
- (id) initWithSize:(CGSize)size images:(NSArray *)images locations:(NSDictionary *)locations;
- (id) initWithAtlasTexture:(SemiSecretTexture *)atlasTexture offset:(CGPoint)offset size:(CGSize)size;

+ (NSMutableDictionary *) textureMap;

@end
