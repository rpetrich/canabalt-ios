//
//  SemiSecretText.h
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

#import <UIKit/UIKit.h>

typedef enum {
  SemiSecretTextEffectNone,
  SemiSecretTextEffectEngravedShadow,
  SemiSecretTextEffectReverseEngravedShadow,
  SemiSecretTextEffectBlurredShadow,
} SemiSecretTextEffect;

typedef enum {
  SemiSecretTextAlignCenter,
  SemiSecretTextAlignLeft,
  SemiSecretTextAlignRight,
} SemiSecretTextAlign;

@class SemiSecretFont;

@interface SemiSecretText : UIView
{
  NSString * text;
  BOOL useSSFont;
  BOOL useUIFont;
  SemiSecretFont * ssfont;
  UIFont * uifont;
  CGColorRef color;
  CGColorRef shadowColor;
  CGGlyph * glyphs;
  unsigned glyphLength;
  CGFloat lineWidth;
  CGFloat textWidth;
  CGFloat textHeight;
  SemiSecretTextEffect effect;
  SemiSecretTextAlign align;
  BOOL wrapped;
  CGFloat lineSpacing;
  BOOL reposition;
  CGFloat padding;
  BOOL wrapOnSpace;
  BOOL debug;
}
+ (id) text;
@property (nonatomic, copy) NSString * text;
@property (nonatomic, assign) CGColorRef color;
@property (nonatomic, assign) CGColorRef shadowColor;
@property (nonatomic, retain) id font;
@property (nonatomic, assign) SemiSecretTextEffect effect;
@property (nonatomic, assign) SemiSecretTextAlign align;
@property (nonatomic, assign,getter=isWrapped) BOOL wrapped;
- (CGFloat) heightForLines:(NSInteger)lines givenWidth:(CGFloat)width;
@property (nonatomic, assign) CGFloat lineSpacing;
@property (nonatomic, assign) BOOL reposition;
@property (nonatomic, assign) CGFloat padding;
@property (nonatomic, assign) BOOL wrapOnSpace;
@property (nonatomic, assign) BOOL debug;
@end
