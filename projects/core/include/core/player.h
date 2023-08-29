/**
 * @file Player.h
 * @author Dmitrii Ivanov (idma88@yandex.ru)
 * @brief Определение класса Игрок
 */
#pragma once

#include <cstdint>
#include <string>
#include <string_view>

#include <core/common.h>

namespace OpenIT {
/**
 * @brief Игрок
 */
class Player
{
  friend class Game;

public:
  /**
   * @brief Конструктор
   *
   * @param[in] nickname Никнейм игрока
   */
  Player(std::string_view nickname = "");

  /**
   * @brief Деструктор
   */
  ~Player() = default;

  /**
   * @brief Получает никнейм игрока
   *
   * @return Возвращает никнейм игрока
   */
  std::string_view GetNickname() const;

  /**
   * @brief Устанавливает никнейм игрока
   *
   * @param[in] nickname Никнейм игрока
   * @return Возвращает true в случае успеха или false в противном случае
   */
  bool SetNickname(std::string_view nickname);

private:
  /// Никнейм игрока
  std::string m_nickname;
  /// Счёт игрока
  ScoreValue m_score;
};
} // namespace OpenIT