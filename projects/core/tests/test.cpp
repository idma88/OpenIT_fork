#include <core/player.h>
#include <gtest/gtest.h>

using namespace OpenIT;

TEST(TestPlayer, ConstructorWithoutParameter_Check)
{
  Player player;

  ASSERT_EQ(player.GetNickname(), "");
}

TEST(TestPlayer, ConstructorWithParameter_Check)
{
  const std::string name = "SomeName";

  Player* player = new Player(name);

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