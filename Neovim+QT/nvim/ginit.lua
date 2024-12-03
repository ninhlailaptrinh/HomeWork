-- Cấu hình cho GUI Neovim (neovim-qt)
local M = {}

function M.setup()
  if vim.fn.exists('g:GuiLoaded') == 1 then
    -- Cấu hình font
    vim.g.fontsize = 12
    vim.g.fontname = 'JetBrainsMono NFM'
    vim.cmd('GuiFont! ' .. vim.g.fontname .. ':h' .. vim.g.fontsize)
    
    -- Bật true color
    vim.opt.termguicolors = true
    
    -- Các phím tắt điều chỉnh font và cấu hình khác giữ nguyên
  end
end

return M