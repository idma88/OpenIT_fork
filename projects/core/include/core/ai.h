/**
 * @file ai.h
 * @author Aleksandr Kohanyuk (shurik_k73@mail.ru)
 * @brief Определение класса ИИ
 */
#pragma once

#include <cstdint>

#include <core/common.h>
#include <core/game.h>

namespace OpenIT {
/**
 * @brief AI
 */
class AI
{
public:
  /**
   * @brief Конструктор
   *
   * @param[in] difficulty Уровень сложности
   * @param[in] axis       Ось, вдоль которой ИИ может передвигать каретку
   */
  AI(const Difficulty& difficulty = Difficulty::EASY, const Axis& axis = Axis::Y);

  /**
   * @brief Деструктор
   */
  ~AI() = default;

  /**
   * @brief Устанавливает уровень сложности
   *
   * @param[in] difficulty Уровень сложности
   */
  void SetDifficulty(const Difficulty& difficulty);

  /**
   * @brief Устанавливает ось, вдоль которой ИИ может передвигать каретку
   *
   * @param[in] axis Ось, вдоль которой ИИ может передвигать каретку
   */
  void SetAxis(const Axis& axis);

  /**
   * @brief Рассчитывает ход
   *
   * @param[in] field   Игровое поле
   * @param[in] carrige Положение каретки
   * @return Возвращает Новое положение каретки, соотвтетвующее выбранной ИИ ячейки
   */
  Position Calculate(const Game::Field& field, Position carrige);

private:
  /**
   * @brief
   *
   * * @param[in]
   */
  int8_t CheckValue(Position carrige, int8_t countItteration, int8_t sum, int8_t bestSum);

private:
  /// Уровень сложности
  Difficulty m_difficulty;
  /// Ось, вдоль которой ИИ может передвигать каретку
  Axis m_axis;
  /// Лучшая сумма за все ходы
  int8_t m_sum;
  /// Текущая позиция игрока
  Position m_current_carrige_pos;
  /// Лучший следующий ход
  Position m_next_the_best_pos;
  /// Кол-во просмотренных ходов ИИ
  int8_t m_countItterationdifficulty = 0;
  /// Копия поля
  Game::Field m_copy_field;
};
} // namespace OpenIT