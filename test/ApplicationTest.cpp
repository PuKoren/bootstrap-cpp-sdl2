#include <cppunit/extensions/HelperMacros.h>
#include "Application.hpp"

class ApplicationTest : public CppUnit::TestFixture
{
  CPPUNIT_TEST_SUITE( ApplicationTest );
  CPPUNIT_TEST( testRegularRun );
  CPPUNIT_TEST( testRunUserEscape );
  CPPUNIT_TEST( testRunWindowEvent );
  CPPUNIT_TEST_SUITE_END();

public:
  void setUp();
  void tearDown();

  void testRegularRun();
  void testRunUserEscape();
  void testRunWindowEvent();
};

// Registers the fixture into the 'registry'
CPPUNIT_TEST_SUITE_REGISTRATION( ApplicationTest );


void
ApplicationTest::setUp() {

}


void
ApplicationTest::tearDown() {

}


void ApplicationTest::testRegularRun() {
  Application app;
  SDL_Renderer* renderer;
  SDL_Event ev;
  CPPUNIT_ASSERT(app.run(renderer, ev));
}

void ApplicationTest::testRunUserEscape() {
  Application app;
  SDL_Renderer* renderer;
  SDL_Event ev;
  ev.type = SDL_KEYDOWN;
  ev.key.keysym.sym = SDLK_ESCAPE;
  CPPUNIT_ASSERT(!app.run(renderer, ev));
}

void ApplicationTest::testRunWindowEvent() {
  Application app;
  SDL_Renderer* renderer;
  SDL_Event ev;
  ev.type = SDL_WINDOWEVENT;
  ev.window.event = SDL_WINDOWEVENT_CLOSE;
  CPPUNIT_ASSERT(!app.run(renderer, ev));
}