//
//  Player.h
//  Canabalt
//
//  Copyright Semi Secret Software 2009-2010. All rights reserved.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
// THE SOFTWARE.
//

@interface Player : FlxSprite
{
  CGFloat jump;
  CGFloat jumpLimit;
  BOOL stumble;
  CGFloat my;

  CGFloat ft;
  CGFloat fc;
  NSArray * feet;
  NSArray * feetC;
  BOOL craneFeet;
  NSString * epitaph;
  BOOL pause;
  BOOL speedy;
}

+ (id) playerWithSpeedy:(BOOL)isSpeedy;
- (id) initWithSpeedy:(BOOL)isSpeedy;

@property (nonatomic) CGFloat jumpLimit;
@property (nonatomic) BOOL stumble;
@property (nonatomic) BOOL craneFeet;
@property (nonatomic, copy) NSString * epitaph;
@property (nonatomic) BOOL pause;
@property (nonatomic, readonly, getter=isSpeedy) BOOL speedy;

@end
