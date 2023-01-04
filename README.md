# Solar System
Модель солнечной системы

## Описание

### Астрономические термины

*Латиницей в скобках указаны соответсвующие терминам обозначения, используемые в программе*

**Астрономический объект** (далее - объект) (*object*) - отдельное небесное тело (например, звезда, планета или луна).

**Звезда** (*star*) - объект, являющийся центром системы.

**Планета** - объект, вращающийся вокруг звезды.

**Луна** - объект, вращающийся вокруг планеты; естественный спутник планеты (например, для Земли - это Луна, а для Марса - Фобос и Деймос).

**Система** (*system*) - совокупность объектов (звезда и её планеты и их луны).

**Солнечная система** (*solar_system*) - частный случай системы, состоящий из звезды (Солнце), планет (Меркурий, Венера, Земля, Марс, Юпитер, Сатурн, Уран, Нептун) и лун (Луна).

**Астрономическая единица** (*au*) - единица измерения расстояний, равная расстоянию от Солнца до Земли (или ~149 597 870 км).

**Плоскость эклиптики** - плоскость обращения Земли вокруг Солнца (плоскость земной орбиты).

**Осеннее равноденствие** (*equinox*) - астрономическое событие, когда при наблюдении с Земли центр Солнца в своём видимом движении по эклиптике пересекает небесный экватор (круг, лежащий в плоскости земного экватора) и переходит из северного полушария небесной сферы в южное. Осеннее равноденствие происходит 22 или 23 сентября каждого года. Для других планет (кроме Земли) осеннее равноденствие происходит в точке пересечения планетой оси, направленной от Солнца к земному осеннему равноденствию.

**Зимнее солнцестояние** -  астрономическое событие, при котором Солнце над горизонтом в полдень находится на минимальной высоте.


### Описание

Solar System - это бэкенд-реализация на C++ модели солнечной системы. Модель по запросу даты выдаёт координаты объектов солнечной системы в астрономических единицах. Плоскость системы координат модели лежит в плоскости эклиптики, центром системы координат является звезда (Солнце). Ось абсцисс (x) направлена от звезды в точку осеннего равноденствия Земли, ось ординат (y) - в точку зимнего солнцестояния Земли. Таким образом, взгляд наблюдателя направлен на север звезды, планеты вращаются против часовой стрелки.
