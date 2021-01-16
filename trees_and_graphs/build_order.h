#include <algorithm>
#include <map>
#include <stack>
#include <string>
#include <unordered_map>
#include <vector>

// Solution 1
class Project {
 public:
  Project(std::string name) : name(name) { dependencyCount = 0; };

  std::string name;
  int dependencyCount;
  std::vector<std::string> children;

  void increaseDependencyCount() { dependencyCount++; }
  void decreaseDependencyCount() { dependencyCount--; }
};

class Graph {
 public:
  Graph(std::vector<std::string> projects,
        std::vector<std::vector<std::string>> dependencies) {
    nodes = std::map<std::string, Project>();
    for (std::string name : projects) {
      nodes.insert(std::make_pair(name, Project(name)));
    }

    for (std::vector<std::string> dependency : dependencies) {
      std::string first = dependency[0];
      std::string second = dependency[1];
      Project *project = &nodes.find(first)->second;
      project->children.push_back(second);
      Project *project2 = &nodes.find(second)->second;
      project2->increaseDependencyCount();
    }
  }

  std::map<std::string, Project> nodes;
};

// Find and add nodes with no dependency to the build list.
// Decreases dependency count on dependent nodes.
// Returns count of added nodes.
int addNodesWithNoDependencies(std::vector<std::string> &buildOrder,
                               Graph *graph, int &offset) {
  int count = 0;
  std::vector<std::string> toErase;
  for (auto &project : graph->nodes) {
    if (project.second.dependencyCount == 0) {
      buildOrder[offset] = project.second.name;
      offset++;
      count++;
      // remove dependencies
      for (std::string child : project.second.children) {
        graph->nodes.find(child)->second.decreaseDependencyCount();
      }
      project.second.children.clear();
      toErase.push_back(project.first);
    }
  }

  // erase nodes.
  for (auto node : toErase) {
    graph->nodes.erase(node);
  }

  return count;
}

std::vector<std::string> getBuildOrder(
    std::vector<std::string> projects,
    std::vector<std::vector<std::string>> dependencies) {
  Graph *graph = new Graph(projects, dependencies);
  std::vector<std::string> buildOrder(projects.size());

  int offset = 0;
  addNodesWithNoDependencies(buildOrder, graph, offset);

  while (offset < projects.size()) {
    if (addNodesWithNoDependencies(buildOrder, graph, offset) == 0) {
      return std::vector<std::string>();
    };
  }

  return buildOrder;
}

// Solution 2: DFS
class Project2 {
 public:
  Project2(std::string name) : name(name) { firstChild = nullptr; }

  void updateFirstChild(Project2 *project) { firstChild = project; }
  std::string name;
  Project2 *firstChild;
};

class Graph2 {
 public:
  Graph2(std::vector<std::string> projects,
         std::vector<std::vector<std::string>> deps) {
    for (auto projectName : projects) {
      Project2 *project = new Project2(projectName);
      nodes.insert({projectName, *project});
    }

    for (auto dep : deps) {
      // TODO assert if nodes[project] does not exist
      nodes.at(dep[0]).firstChild = &nodes.at(dep[1]);
    }
  }

  std::unordered_map<std::string, Project2> nodes;
};

std::vector<std::string> getBuildOrder2(
    std::vector<std::string> projects,
    std::vector<std::vector<std::string>> deps) {
  Graph2 graph(projects, deps);
  std::stack<std::string> stack;
  int offset = projects.size() - 1;
  std::vector<std::string> buildOrder(projects.size());

  auto isAlreadyInBuildOrder = [&](std::string projectName) -> bool {
    return std::find(buildOrder.begin(), buildOrder.end(), projectName) !=
           buildOrder.end();
  };

  for (auto projectName : projects) {
    Project2 project = graph.nodes.at(projectName);

    if (isAlreadyInBuildOrder(project.name)) continue;
    stack.push(project.name);
    while (project.firstChild != nullptr) {
      project = *graph.nodes.at(project.name).firstChild;
      if (isAlreadyInBuildOrder(project.name)) break;
      stack.push(project.name);
    }

    while (stack.size() > 0) {
      buildOrder[offset] = stack.top();
      offset--;
      stack.pop();
    }
  }

  return buildOrder;
}