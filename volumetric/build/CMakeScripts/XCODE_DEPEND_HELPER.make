# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.CGL.Debug:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/Debug/libCGL_osx.a:
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/Debug/libCGL_osx.a


PostBuild.glew.Debug:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/Debug/libglew.a:
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/Debug/libglew.a


PostBuild.glfw.Debug:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/Debug/libglfw3.a:
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/Debug/libglfw3.a


PostBuild.pathtracer.Debug:
PostBuild.CGL.Debug: /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/Debug/pathtracer
PostBuild.glew.Debug: /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/Debug/pathtracer
PostBuild.glfw.Debug: /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/Debug/pathtracer
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/Debug/pathtracer:\
	/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/Debug/libCGL_osx.a\
	/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/Debug/libglew.a\
	/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/Debug/libglfw3.a\
	/usr/local/lib/libfreetype.dylib\
	/usr/local/lib/libfreetype.dylib
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/Debug/pathtracer


PostBuild.CGL.Release:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/Release/libCGL_osx.a:
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/Release/libCGL_osx.a


PostBuild.glew.Release:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/Release/libglew.a:
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/Release/libglew.a


PostBuild.glfw.Release:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/Release/libglfw3.a:
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/Release/libglfw3.a


PostBuild.pathtracer.Release:
PostBuild.CGL.Release: /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/Release/pathtracer
PostBuild.glew.Release: /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/Release/pathtracer
PostBuild.glfw.Release: /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/Release/pathtracer
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/Release/pathtracer:\
	/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/Release/libCGL_osx.a\
	/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/Release/libglew.a\
	/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/Release/libglfw3.a\
	/usr/local/lib/libfreetype.dylib\
	/usr/local/lib/libfreetype.dylib
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/Release/pathtracer


PostBuild.CGL.MinSizeRel:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/MinSizeRel/libCGL_osx.a:
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/MinSizeRel/libCGL_osx.a


PostBuild.glew.MinSizeRel:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/MinSizeRel/libglew.a:
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/MinSizeRel/libglew.a


PostBuild.glfw.MinSizeRel:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/MinSizeRel/libglfw3.a:
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/MinSizeRel/libglfw3.a


PostBuild.pathtracer.MinSizeRel:
PostBuild.CGL.MinSizeRel: /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/MinSizeRel/pathtracer
PostBuild.glew.MinSizeRel: /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/MinSizeRel/pathtracer
PostBuild.glfw.MinSizeRel: /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/MinSizeRel/pathtracer
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/MinSizeRel/pathtracer:\
	/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/MinSizeRel/libCGL_osx.a\
	/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/MinSizeRel/libglew.a\
	/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/MinSizeRel/libglfw3.a\
	/usr/local/lib/libfreetype.dylib\
	/usr/local/lib/libfreetype.dylib
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/MinSizeRel/pathtracer


PostBuild.CGL.RelWithDebInfo:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/RelWithDebInfo/libCGL_osx.a:
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/RelWithDebInfo/libCGL_osx.a


PostBuild.glew.RelWithDebInfo:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/RelWithDebInfo/libglew.a:
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/RelWithDebInfo/libglew.a


PostBuild.glfw.RelWithDebInfo:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a:
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a


PostBuild.pathtracer.RelWithDebInfo:
PostBuild.CGL.RelWithDebInfo: /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/RelWithDebInfo/pathtracer
PostBuild.glew.RelWithDebInfo: /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/RelWithDebInfo/pathtracer
PostBuild.glfw.RelWithDebInfo: /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/RelWithDebInfo/pathtracer
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/RelWithDebInfo/pathtracer:\
	/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/RelWithDebInfo/libCGL_osx.a\
	/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/RelWithDebInfo/libglew.a\
	/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a\
	/usr/local/lib/libfreetype.dylib\
	/usr/local/lib/libfreetype.dylib
	/bin/rm -f /Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/RelWithDebInfo/pathtracer




# For each target create a dummy ruleso the target does not have to exist
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/Debug/libglew.a:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/MinSizeRel/libglew.a:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/RelWithDebInfo/libglew.a:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glew/Release/libglew.a:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/Debug/libglfw3.a:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/MinSizeRel/libglfw3.a:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/RelWithDebInfo/libglfw3.a:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/deps/glfw/src/Release/libglfw3.a:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/Debug/libCGL_osx.a:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/MinSizeRel/libCGL_osx.a:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/RelWithDebInfo/libCGL_osx.a:
/Users/emmatao/desktop/cg/p3-1-pathtracer-EmmmaTao/build/CGL/src/Release/libCGL_osx.a:
/usr/local/lib/libfreetype.dylib:
