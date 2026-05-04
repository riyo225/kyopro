import os
import json
import re
import subprocess

# 設定
LIB_DIR = os.path.expanduser("~/kyopro/lib")

def get_windows_snippet_path():
    try:
        # stderr=subprocess.DEVNULL で警告文などの不要な出力を完全に捨てる
        # decode("cp932") でWindows側のShift-JISを正しく処理する
        appdata_win = subprocess.check_output(
            ["cmd.exe", "/c", "echo %APPDATA%"], 
            cwd="/",
            stderr=subprocess.DEVNULL
        ).decode("cp932").strip()
        
        appdata_wsl = subprocess.check_output(
            ["wslpath", "-u", appdata_win],
            cwd="/",
            stderr=subprocess.DEVNULL
        ).decode("utf-8").strip()
        
        return os.path.join(appdata_wsl, "Code", "User", "snippets", "cpp.json")
    except Exception as e:
        print(f"Windowsパスの自動取得に失敗しました: {e}")
        return "/mnt/c/Users/USERNAME/AppData/Roaming/Code/User/snippets/cpp.json"

OUTPUT_PATH = get_windows_snippet_path()

def generate():
    snippets = {}
    
    # prefixを抽出するための正規表現: // [prefix: name1, name2]
    prefix_re = re.compile(r"//\s*\[prefix:\s*(.+?)\]")

    for root, dirs, files in os.walk(LIB_DIR):
        for file in files:
            if not file.endswith(".cpp"): continue
            
            path = os.path.join(root, file)
            filename_base = os.path.splitext(file)[0]
            
            with open(path, "r", encoding="utf-8") as f:
                lines = f.readlines()
                
            # 1行目付近からprefixを探す
            prefix = filename_base # 見つからなかった時のデフォルト
            body_start_index = 0
            
            for i, line in enumerate(lines[:5]): # 冒頭5行目までをスキャン
                match = prefix_re.search(line)
                if match:
                    raw_prefixes = match.group(1) # ここを修正: math -> match
                    # カンマやスペースで分割してリスト化
                    prefix_list = [p.strip() for p in re.split(r'[,\s]+', raw_prefixes) if p.strip()]
                    prefix = prefix_list
                    body_start_index = i + 1
                    break
            
            content = "".join(lines[body_start_index:]).strip()
            
            # スニペットとして登録（キー名は管理用なのでファイル名にしておく）
            snippets[f"Library: {filename_base}"] = {
                # "scope": "cpp",
                "prefix": prefix,
                "body": content.splitlines(),
                "description": f"File: {file}"
            }
            
    os.makedirs(os.path.dirname(OUTPUT_PATH), exist_ok=True)
    
    with open(OUTPUT_PATH, "w", encoding="utf-8") as f:
        json.dump(snippets, f, indent=4, ensure_ascii=False)
    
    print(f"✅ {len(snippets)} 個のスニペットを同期しました: {OUTPUT_PATH}")

if __name__ == "__main__":
    generate()