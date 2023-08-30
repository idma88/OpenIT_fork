/**
 * @file ai.h
 * @author Aleksandr Kohanyuk (shurik_k73@mail.ru)
 * @author Dmitrii Ivanov (idma88@yandex.ru)
 * @brief Определение класса ИИ
 */
#pragma once

#include <cstdint>
#include <tuple>

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
  Position Calculate(const Game::Field& field, Position carrige) const;

private:
  /**
   * @brief Имитирует процесс совершения последовательности ходов с поиском лучшего хода
   *
   * @param[in] field   Игровое поле
   * @param[in] carrige Положение каретки
   * @param[in] axis    Ось, вдоль которой можно передвигать каретку
   * @param[in] steps   Количество рекурсивных шагов
   * @return Возвращает кортеж из взвешенной суммы очков и лучшей позиции
   */
  std::tuple<ScoreValue, Position> MakeMove(Game::Field field,
                                            Position    carrige,
                                            Axis        axis,
                                            uint8_t     steps) const;

private:
  /// Уровень сложности
  Difficulty m_difficulty;
  /// Ось, вдоль которой ИИ может передвигать каретку
  Axis m_axis;
};
} // namespace OpenIT