#include <core/player.h>

#include "gtest/gtest.h"

using namespace OpenIT;

class TestPlayer : public ::testing::Test
{
protected:
  void SetUp() override { m_player = new Player(); }

  void TearDown() override { delete m_player; }

  Player* m_player;
};

TEST_F(TestPlayer, SetNickname_Check)
{
  const std::string name = "SomeName";

  m_player->SetNickname(name);

  ASSERT_EQ(m_player->GetNickname(), name);
}