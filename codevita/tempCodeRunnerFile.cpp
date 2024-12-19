struct Animal
// {
//     string name;
//     int voltageThreshold;
// };

// map<string, int> parseAnimalData(const string &input)
// {
//     map<string, int> animalData;
//     stringstream ss(input);
//     string pair;

//     while (getline(ss, pair, ' '))
//     {
//         size_t pos = pair.find(':');
//         string name = pair.substr(0, pos);
//         int threshold = stoi(pair.substr(pos + 1));
//         animalData[name] = threshold;
//     }

//     return animalData;
// }

// // Function to calculate points on the wire segment
// vector<pair<int, int>> calculatePoints(int x1, int y1, int x2, int y2)
// {
//     vector<pair<int, int>> points;

//     if (x1 == x2)
//     { // Vertical line
//         int start = min(y1, y2);
//         int end = max(y1, y2);
//         for (int i = start; i <= end; ++i)
//         {
//             points.push_back({x1, i});
//         }
//     }
//     else if (y1 == y2)
//     { // Horizontal line
//         int start = min(x1, x2);
//         int end = max(x1, x2);
//         for (int i = start; i <= end; ++i)
//         {
//             points.push_back({i, y1});
//         }
//     }
//     else
//     { // Diagonal line
//         int dx = x2 - x1;
//         int dy = y2 - y1;
//         int steps = max(abs(dx), abs(dy));
//         for (int i = 0; i <= steps; ++i)
//         {
//             int x = x1 + i * dx / steps;
//             int y = y1 + i * dy / steps;
//             points.push_back({x, y});
//         }
//     }

//     return points;
// }

// // Function to calculate the voltage at each intersection
// int calculateVoltage(const vector<vector<pair<int, int>>> &wires, const map<pair<int, int>, vector<int>> &pointMap, pair<int, int> point)
// {
//     vector<int> segmentIDs = pointMap.at(point);
//     int numWires = segmentIDs.size();

//     // Calculate the minimum number of cells touched by all wires
//     int minCells = INT_MAX;
//     for (int i : segmentIDs)
//     {
//         vector<pair<int, int>> points = wires[i];
//         int left = 0, right = 0;
//         for (auto p : points)
//         {
//             if (p < point)
//                 left++;
//             else if (p > point)
//                 right++;
//         }
//         minCells = min(minCells, min(left, right));
//     }

//     // Voltage at the intersection is number of wires * minimum number of cells
//     return numWires * minCells;
// }

// int main()
// {
// #ifndef ONLINE_JUDGE
//     freopen("input.txt", "r", stdin);
//     freopen("output.txt", "w", stdout);
// #endif
//     int N;
//     cin >> N;

//     vector<vector<pair<int, int>>> wires(N);
//     map<pair<int, int>, vector<int>> pointMap;

//     // Read wire segments and store their points
//     for (int i = 0; i < N; ++i)
//     {
//         int x1, y1, x2, y2;
//         cin >> x1 >> y1 >> x2 >> y2;

//         vector<pair<int, int>> points = calculatePoints(x1, y1, x2, y2);
//         wires[i] = points;

//         // Map points to wire segments
//         for (auto &point : points)
//         {
//             pointMap[point].push_back(i);
//         }
//     }

//     cin.ignore(); // Ignore the newline character after the wire coordinates

//     // Read animal voltage thresholds
//     string animalsInput;
//     getline(cin, animalsInput);

//     map<string, int> animalData = parseAnimalData(animalsInput);

//     // Read the animal that touched the fence
//     string animalName;
//     cin >> animalName;

//     for (const auto &elem : animalData)
//     {
//         cout << elem.first << " " << elem.second << "\n";
//     }

//     // Calculate the total voltage at all intersections
//     int totalVoltage = 0;
//     for (auto &p : pointMap)
//     {
//         auto &point = p.first;
//         auto &segmentIDs = p.second;
//         if (segmentIDs.size() > 1)
//         {
//             totalVoltage += calculateVoltage(wires, pointMap, point);
//         }
//     }

//     if (animalData[animalName] < totalVoltage)
//     {
//         cout << "Yes" << endl;
//     }
//     else
//     {
//         cout << "No" << endl;
//     }

//     int numAnimals = animalData.size();
//     int animalsThatDie = 0;

//     for (auto &animal : animalData)
//     {
//         auto &name = animal.first;
//         auto &threshold = animal.second;
//         if (threshold < totalVoltage)
//         {
//             animalsThatDie++;
//         }
//     }

//     double probability = (double)animalsThatDie / numAnimals;
//     cout << fixed << setprecision(2) << probability << endl;

//     cout << animalsInput;
//     cout << endl
//          << animalName;

//     return 0;
// }
