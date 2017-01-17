#include "gtest/gtest.h"
#include "gmock/gmock.h"

#include <utility>
#include <string>
#include <iostream>
#include <memory>
#include <fstream>
#include <vector>

#include "IFileLoaderDelegate.h"
#include "Vec2i.h"
#include "IMapElement.h"
#include "CTeam.h"
#include "CActor.h"
#include "CGameDelegate.h"
#include "CMap.h"
#include "IRenderer.h"
#include "CGame.h"

using ::testing::Return;
using ::testing::_;

class MockRenderer : public Knights::IRenderer {
public:

  MOCK_METHOD2(drawMap, void( Knights::CMap &map, std::shared_ptr<Knights::CActor> current ) );
  MOCK_METHOD0(getInput, char());
};

class MockFileLoader : public Knights::IFileLoaderDelegate {
public:

  MOCK_METHOD1( loadFileFromPath, std::string( const std::string& path ) );
  MOCK_METHOD1( loadBinaryFileFromPath, std::vector<char>( const std::string& path ) );
  MOCK_METHOD0( getFilePathPrefix, std::string());
};


TEST(TestCGame, GameWillRefreshUponValidMoveTest ) {
  
  auto mockFileLoader = std::make_shared<MockFileLoader>();
  auto renderer = std::make_shared<MockRenderer>(); 
  auto delegate = std::make_shared<Knights::CGameDelegate>();
  auto game = std::make_shared<Knights::CGame>( mockFileLoader, renderer, delegate );

  ON_CALL(*renderer, getInput()).WillByDefault(Return(Knights::kMovePlayerNorthCommand));
  EXPECT_CALL(*renderer, drawMap(_,_));
  game->tick();
}



TEST(TestCGame, GameWillNotTryToLoadFileFromBinaryTest ) {
  
  auto mockFileLoader = std::make_shared<MockFileLoader>();
  auto renderer = std::make_shared<MockRenderer>(); 
  auto delegate = std::make_shared<Knights::CGameDelegate>();

  EXPECT_CALL(*mockFileLoader, loadBinaryFileFromPath(_));
  auto game = std::make_shared<Knights::CGame>( mockFileLoader, renderer, delegate );
}

