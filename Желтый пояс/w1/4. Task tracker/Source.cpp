#include <string>
#include <tuple>
#include <utility>
#include <iostream>
#include <algorithm>

#include "Header.h"

using namespace std;

class TeamTasks {
public:
    // ѕолучить статистику по статусам задач конкретного разработчика
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        if (m.find(person) != m.end())
        {
            return m.at(person);
        }
    }

    // ƒобавить новую задачу (в статусе NEW) дл€ конкретного разработчитка
    void AddNewTask(const string& person) {
        ++m[person][TaskStatus::NEW];
    }

    // ќбновить статусы по данному количеству задач конкретного разработчика,
    // подробности см. ниже
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count) {
        if (m.find(person) != m.end())
        {
            TasksInfo updated_tasks, untouched_tasks;
            auto& t_info = m.at(person);
            int temp_new = 0, temp_progress = 0, temp_testing = 0;
 
            if (t_info.find(TaskStatus::NEW) != end(t_info) )
            {
                if(task_count)
                {

                    temp_new = min(t_info.at(TaskStatus::NEW), task_count);
                    updated_tasks[TaskStatus::IN_PROGRESS] = temp_new;
                    task_count -= temp_new;
                    t_info.at(TaskStatus::NEW) -= temp_new;
                    if (t_info.at(TaskStatus::NEW) > 0)
                    {
                        untouched_tasks[TaskStatus::NEW] = t_info.at(TaskStatus::NEW);
                    }
                    else {
                        t_info.erase(TaskStatus::NEW);
                    }
                }
                else
                {
                    int temp = t_info.at(TaskStatus::NEW);
                    untouched_tasks[TaskStatus::NEW] = temp;
                }
            }

            if (t_info.find(TaskStatus::IN_PROGRESS) != end(t_info))
            {
                if (task_count)
                {

                    temp_progress = min(t_info.at(TaskStatus::IN_PROGRESS), task_count);
                    updated_tasks[TaskStatus::TESTING] = temp_progress;
                    task_count -= temp_progress;
                    t_info.at(TaskStatus::IN_PROGRESS) -= temp_progress;
                    if (t_info.at(TaskStatus::IN_PROGRESS) > 0)
                    {
                        untouched_tasks[TaskStatus::IN_PROGRESS] = t_info.at(TaskStatus::IN_PROGRESS);
                    }
                    else {
                        t_info.erase(TaskStatus::IN_PROGRESS);
                    }
                }
                else
                {
                    int temp = t_info.at(TaskStatus::IN_PROGRESS);
                    untouched_tasks[TaskStatus::IN_PROGRESS] = temp;
                }
            }

            if (t_info.find(TaskStatus::TESTING) != end(t_info))
            {
                if (task_count)
                {

                    temp_testing = min(t_info.at(TaskStatus::TESTING), task_count);
                    updated_tasks[TaskStatus::DONE] = temp_testing;
                    task_count -= temp_testing;
                    t_info.at(TaskStatus::TESTING) -= temp_testing;
                    if (t_info.at(TaskStatus::TESTING) > 0)
                    {
                        untouched_tasks[TaskStatus::TESTING] = t_info.at(TaskStatus::TESTING);
                    }
                    else {
                        t_info.erase(TaskStatus::TESTING);
                    }
                }
                else
                {
                    int temp = t_info.at(TaskStatus::TESTING);
                    untouched_tasks[TaskStatus::TESTING] = temp;
                }
            }

            if (temp_new>0)
                t_info[TaskStatus::IN_PROGRESS] += temp_new;
            if(temp_progress>0)
                t_info[TaskStatus::TESTING] += temp_progress;
            if (temp_testing > 0)
                t_info[TaskStatus::DONE] += temp_testing;
            return make_tuple(updated_tasks, untouched_tasks);
        }
        else {
            return make_tuple(TasksInfo{}, TasksInfo{});
        }
    }
public:
    map<string, TasksInfo> m;
};

// ѕринимаем словарь по значению, чтобы иметь возможность
// обращатьс€ к отсутствующим ключам с помощью [] и получать 0,
// не мен€€ при этом исходный словарь
void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}

int main() {
    TeamTasks tasks;

    
    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    cout << "tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    cout << endl;

    TasksInfo updated_tasks, untouched_tasks;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Alice", 5);
    cout << "Updated tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched tasks: ";
    PrintTasksInfo(untouched_tasks);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    cout << endl;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Alice", 5);
    cout << "Updated tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched tasks: ";
    PrintTasksInfo(untouched_tasks);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    cout << endl;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Alice", 1);
    cout << "Updated tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched tasks: ";
    PrintTasksInfo(untouched_tasks);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    cout << endl;

    for (int i = 0; i < 5; ++i) {
        tasks.AddNewTask("Alice");
    }
    cout << "tasks: ";
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    cout << endl;

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Alice", 2);
    cout << "Updated tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched tasks: ";
    PrintTasksInfo(untouched_tasks);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    cout << endl;

    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));

    tie(updated_tasks, untouched_tasks) =
        tasks.PerformPersonTasks("Alice", 4);
    cout << "Updated tasks: ";
    PrintTasksInfo(updated_tasks);
    cout << "Untouched tasks: ";
    PrintTasksInfo(untouched_tasks);
    PrintTasksInfo(tasks.GetPersonTasksInfo("Alice"));
    cout << endl;

    return 0;
}
