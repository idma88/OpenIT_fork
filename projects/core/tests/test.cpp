#include <core/player.h>
#include <gtest/gtest.h>

using namespace OpenIT;

TEST(TestPlayer, Constructor_Check)
{
  Player* player = new Player();

  ASSERT_EQ(player->GetNickname(), "");

  delete player;

  const std::string name = "SomeName";

  player = new Player(name);

  ASSERT_EQ(player->GetNickname(), name);

  delete player;
}

TEST(TestPlayer, SetNickname_Check)
{
  Player* player = new Player();

  const std::string name = "SomeName";

  player->SetNickname(name);

  ASSERT_EQ(player->GetNickname(), name);

  delete player;
}