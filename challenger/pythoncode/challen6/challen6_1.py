import math
from concurrent.futures import ThreadPoolExecutor

def euclidean_distance(p1, p2):
    return math.sqrt((p1[0] - p2[0]) ** 2 + (p1[1] - p2[1]) ** 2)

def closest_pair_recursive(points):
    if len(points) < 2:
        return float('inf')
    if len(points) == 2:
        return euclidean_distance(points[0], points[1])
    
    mid = len(points) // 2
    left_half = points[:mid]
    right_half = points[mid:]
    
    # Tính toán song song cho hai nửa
    with ThreadPoolExecutor(max_workers=2) as executor:
        future_left = executor.submit(closest_pair_recursive, left_half)
        future_right = executor.submit(closest_pair_recursive, right_half)
        
        d_left = future_left.result()
        d_right = future_right.result()
    
    d_min = min(d_left, d_right)
    
    mid_x = points[mid][0]
    strip = [p for p in points if abs(p[0] - mid_x) < d_min]
    strip.sort(key=lambda p: p[1])
    
    for i in range(len(strip)):
        for j in range(i + 1, len(strip)):
            if strip[j][1] - strip[i][1] >= d_min:
                break
            d_min = min(d_min, euclidean_distance(strip[i], strip[j]))
    
    return d_min

def closest_pair(points):
    points.sort()
    return closest_pair_recursive(points)

def main(input_file):
    results = []
    
    with open(input_file, "r") as file:
        lines = file.readlines()
    
    num_maps = int(lines[0].strip())
    index = 1
    for _ in range(num_maps):
        num_points = int(lines[index].strip())
        index += 1
        points = []
        for _ in range(num_points):
            x, y = map(int, lines[index].strip().split())
            points.append((x, y))
            index += 1
        result = closest_pair(points)
        results.append(f"{result:.4f}")
    
    return results

if __name__ == "__main__":
    # Example input file path
    output = main("D:\\code\\CTDLGTVSOOP\\challenger\\pythoncode\\challen6\\input.txt")
    for result in output:
        print(result)
