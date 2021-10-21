class Solution {
public:

    char cut_front(string & str) // возвращает первый элемент строки удаляя его из строки.
        {
            char bit = str.at(0);
            str.erase(str.begin());
            return bit;
        };

    string convert(string s, int numRows)// основная функция 
    {
        vector<string> lines(numRows);// линии для кодировки строки
        bool up = 0; // индикатор движения кодировки вверх по строкам
        int it = -1; // итератор для движения по линиям.
        string res; // ответ.
        
        if(numRows == 1) return s; // если количество линий равно 1 ничего делать не нужно.
        
        // кодируем строки в несколько линий
        numRows--;
        while(s.size()) // пока строка не кончилась
            {
                if(up) it--; // итератор увеличивается при движении вниз и уменьшается при движении вниз
                    else it++; 
                
                lines.at(it) += cut_front(s); // записываем  символ в соответствующую линию.
                
                // меняем индикатор двидения вврерх/вниз в зависимости от достижения первой и последней линии.
                if(it == numRows) up = 1;
                    else if (it == 0 && up) up = 0;
            };
        numRows++;

        // записываем все получившиеся линии в одну строку
        for(auto & i : lines)
            {
                res += i;
            }
            
        return res;
    }
};