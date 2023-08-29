/**
 * @file ai.cpp
 * @author Aleksandr Kohanyuk (shurik_k73@mail.ru)
 * @author Dmitrii Ivanov (idma88@yandex.ru)
 * @brief Определение класса ИИ
 */
#include <optional>

#include <core/ai.h>

namespace OpenIT {

AI::AI(const Difficulty& difficulty = Difficulty::MEDIUM, const Axis& axis = Axis::X)
  : m_difficulty(difficulty)
  , m_axis(axis)
{
}

void
AI::SetDifficulty(const Difficulty& difficulty)
{
  m_difficulty = difficulty;
}

void
AI::SetAxis(const Axis& axis)
{
  m_axis = axis;
}

Position
AI::Calculate(const Game::Field& field, Position carriage)
{
  return std::get<1>(MakeMove(field, carriage, m_axis, m_difficulty * 2));
}

std::tuple<int, Position>
AI::MakeMove(Game::Field field, Position carrige, Axis axis, int steps)
{
  if (steps == 0) return 0;

  auto swapAxis = [](Axis axis) {
    if (axis == Axis::X) return Axis::Y else Axis::X;
  };

  std::optional<int> bestScore;
  Position           bestPos;

  for (int8_t i = 0; i < FIELD_SIZE; ++i) {
    Game::Field curField = field;
    Position    curPos;

    if (axis == Axis::X)
      curPos = { i, carrige.y };
    else
      curPos = { carrige.x, i };

    const int posIndex = curPos.x + curPos.y * FIELD_SIZE;
    if (curField[posIndex] == 0) continue;

    int cellValue      = curField[posIndex];
    curField[posIndex] = 0;

    std::tuple<int, Position> recursiveResult =
      MakeMove(curField, curPos, swapAxis(axis), steps - 1);

    int curScore = cellValue + (axis == m_axis ? -1 : 1) * get<0>(recursiveResult);

    if (!bestScore) {
      bestScore = curScore;
      bestPos   = get<1>(recursiveResult);
    } else if (curScore > bestScore) {
      bestScore = curScore;
      bestPos   = get<1>(recursiveResult);
    }
  };

  return std::make_tupe<int, Position>(bestScore, bestPos);
}

} // namespace OpenIT
