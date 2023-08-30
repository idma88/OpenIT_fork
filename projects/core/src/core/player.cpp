/**
 * @file Player.cpp
 * @author Dmitrii Ivanov (idma88@yandex.ru)
 * @author Denis Koinash (den.koinash@gmail.com)
 * @brief Реализация класса Игрок
 */

#include <core/player.h>

namespace OpenIT {

Player::Player(std::string_view nickname)
  : m_nickname(nickname)
  , m_score(0)
{
}

std::string_view
Player::GetNickname() const
{
  return m_nickname;
}

bool
Player::SetNickname(std::string_view nickname)
{
  if (!nickname.empty()) {
    m_nickname = nickname;
    return true;
  }
  return false;
}

} // namespace OpenIT