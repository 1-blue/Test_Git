<Global.Microsoft.VisualBasic.CompilerServices.DesignerGenerated()>
Partial Class Form1
    Inherits System.Windows.Forms.Form

    'Form은 Dispose를 재정의하여 구성 요소 목록을 정리합니다.
    <System.Diagnostics.DebuggerNonUserCode()>
    Protected Overrides Sub Dispose(ByVal disposing As Boolean)
        Try
            If disposing AndAlso components IsNot Nothing Then
                components.Dispose()
            End If
        Finally
            MyBase.Dispose(disposing)
        End Try
    End Sub

    'Windows Form 디자이너에 필요합니다.
    Private components As System.ComponentModel.IContainer

    '참고: 다음 프로시저는 Windows Form 디자이너에 필요합니다.
    '수정하려면 Windows Form 디자이너를 사용하십시오.  
    '코드 편집기에서는 수정하지 마세요.
    <System.Diagnostics.DebuggerStepThrough()>
    Private Sub InitializeComponent()
        Me.components = New System.ComponentModel.Container()
        Me.lb_ampm = New System.Windows.Forms.Label()
        Me.lb_hour = New System.Windows.Forms.Label()
        Me.lb_minute = New System.Windows.Forms.Label()
        Me.lb_second = New System.Windows.Forms.Label()
        Me.cb_room_select = New System.Windows.Forms.ComboBox()
        Me.cb_hour = New System.Windows.Forms.ComboBox()
        Me.lb_info_1 = New System.Windows.Forms.Label()
        Me.cb_minute = New System.Windows.Forms.ComboBox()
        Me.lb_info_2 = New System.Windows.Forms.Label()
        Me.cb_useTime = New System.Windows.Forms.ComboBox()
        Me.btn_reservation = New System.Windows.Forms.Button()
        Me.tb_reservation_info = New System.Windows.Forms.TextBox()
        Me.btn_fold = New System.Windows.Forms.Button()
        Me.lb_reservation_info = New System.Windows.Forms.Label()
        Me.lbox_reservation_list = New System.Windows.Forms.ListBox()
        Me.btn_reservation_reseve = New System.Windows.Forms.Button()
        Me.gb_reservation_info = New System.Windows.Forms.GroupBox()
        Me.lb_useTime = New System.Windows.Forms.Label()
        Me.lb_startTime = New System.Windows.Forms.Label()
        Me.lb_room_number = New System.Windows.Forms.Label()
        Me.gb_room_state = New System.Windows.Forms.GroupBox()
        Me.checkbox_room5 = New System.Windows.Forms.CheckBox()
        Me.checkbox_room4 = New System.Windows.Forms.CheckBox()
        Me.checkbox_room3 = New System.Windows.Forms.CheckBox()
        Me.checkbox_room2 = New System.Windows.Forms.CheckBox()
        Me.checkbox_room1 = New System.Windows.Forms.CheckBox()
        Me.btn_open = New System.Windows.Forms.Button()
        Me.dlayTimer = New System.Windows.Forms.Timer(Me.components)
        Me.gb_reservation_info.SuspendLayout()
        Me.gb_room_state.SuspendLayout()
        Me.SuspendLayout()
        '
        'lb_ampm
        '
        Me.lb_ampm.AutoSize = True
        Me.lb_ampm.Font = New System.Drawing.Font("돋움", 15.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(129, Byte))
        Me.lb_ampm.Location = New System.Drawing.Point(12, 9)
        Me.lb_ampm.Name = "lb_ampm"
        Me.lb_ampm.Size = New System.Drawing.Size(51, 20)
        Me.lb_ampm.TabIndex = 0
        Me.lb_ampm.Text = "오전"
        '
        'lb_hour
        '
        Me.lb_hour.AutoSize = True
        Me.lb_hour.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.lb_hour.Font = New System.Drawing.Font("돋움", 15.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(129, Byte))
        Me.lb_hour.Location = New System.Drawing.Point(62, 9)
        Me.lb_hour.Name = "lb_hour"
        Me.lb_hour.Size = New System.Drawing.Size(41, 20)
        Me.lb_hour.TabIndex = 0
        Me.lb_hour.Text = "00:"
        '
        'lb_minute
        '
        Me.lb_minute.AutoSize = True
        Me.lb_minute.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.lb_minute.Font = New System.Drawing.Font("돋움", 15.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(129, Byte))
        Me.lb_minute.Location = New System.Drawing.Point(97, 9)
        Me.lb_minute.Name = "lb_minute"
        Me.lb_minute.Size = New System.Drawing.Size(41, 20)
        Me.lb_minute.TabIndex = 0
        Me.lb_minute.Text = "12:"
        '
        'lb_second
        '
        Me.lb_second.AutoSize = True
        Me.lb_second.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.lb_second.Font = New System.Drawing.Font("돋움", 15.0!, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, CType(129, Byte))
        Me.lb_second.Location = New System.Drawing.Point(131, 9)
        Me.lb_second.Name = "lb_second"
        Me.lb_second.Size = New System.Drawing.Size(33, 20)
        Me.lb_second.TabIndex = 0
        Me.lb_second.Text = "00"
        '
        'cb_room_select
        '
        Me.cb_room_select.DropDownStyle = System.Windows.Forms.ComboBoxStyle.DropDownList
        Me.cb_room_select.FormattingEnabled = True
        Me.cb_room_select.Location = New System.Drawing.Point(17, 49)
        Me.cb_room_select.Name = "cb_room_select"
        Me.cb_room_select.Size = New System.Drawing.Size(371, 20)
        Me.cb_room_select.TabIndex = 1
        '
        'cb_hour
        '
        Me.cb_hour.FormattingEnabled = True
        Me.cb_hour.Location = New System.Drawing.Point(17, 93)
        Me.cb_hour.Name = "cb_hour"
        Me.cb_hour.Size = New System.Drawing.Size(63, 20)
        Me.cb_hour.TabIndex = 2
        '
        'lb_info_1
        '
        Me.lb_info_1.AutoSize = True
        Me.lb_info_1.Location = New System.Drawing.Point(86, 96)
        Me.lb_info_1.Name = "lb_info_1"
        Me.lb_info_1.Size = New System.Drawing.Size(17, 12)
        Me.lb_info_1.TabIndex = 3
        Me.lb_info_1.Text = "시"
        '
        'cb_minute
        '
        Me.cb_minute.FormattingEnabled = True
        Me.cb_minute.Location = New System.Drawing.Point(116, 93)
        Me.cb_minute.Name = "cb_minute"
        Me.cb_minute.Size = New System.Drawing.Size(63, 20)
        Me.cb_minute.TabIndex = 2
        '
        'lb_info_2
        '
        Me.lb_info_2.AutoSize = True
        Me.lb_info_2.Location = New System.Drawing.Point(185, 96)
        Me.lb_info_2.Name = "lb_info_2"
        Me.lb_info_2.Size = New System.Drawing.Size(17, 12)
        Me.lb_info_2.TabIndex = 3
        Me.lb_info_2.Text = "분"
        '
        'cb_useTime
        '
        Me.cb_useTime.FormattingEnabled = True
        Me.cb_useTime.Location = New System.Drawing.Point(218, 93)
        Me.cb_useTime.Name = "cb_useTime"
        Me.cb_useTime.Size = New System.Drawing.Size(170, 20)
        Me.cb_useTime.TabIndex = 5
        '
        'btn_reservation
        '
        Me.btn_reservation.FlatStyle = System.Windows.Forms.FlatStyle.System
        Me.btn_reservation.Location = New System.Drawing.Point(17, 145)
        Me.btn_reservation.Name = "btn_reservation"
        Me.btn_reservation.Size = New System.Drawing.Size(371, 23)
        Me.btn_reservation.TabIndex = 6
        Me.btn_reservation.Text = "예약하기"
        Me.btn_reservation.UseVisualStyleBackColor = True
        '
        'tb_reservation_info
        '
        Me.tb_reservation_info.Location = New System.Drawing.Point(17, 189)
        Me.tb_reservation_info.Multiline = True
        Me.tb_reservation_info.Name = "tb_reservation_info"
        Me.tb_reservation_info.Size = New System.Drawing.Size(371, 167)
        Me.tb_reservation_info.TabIndex = 7
        '
        'btn_fold
        '
        Me.btn_fold.Location = New System.Drawing.Point(406, 12)
        Me.btn_fold.Name = "btn_fold"
        Me.btn_fold.Size = New System.Drawing.Size(26, 344)
        Me.btn_fold.TabIndex = 8
        Me.btn_fold.Text = ">"
        Me.btn_fold.UseVisualStyleBackColor = True
        '
        'lb_reservation_info
        '
        Me.lb_reservation_info.AutoSize = True
        Me.lb_reservation_info.Location = New System.Drawing.Point(470, 23)
        Me.lb_reservation_info.Name = "lb_reservation_info"
        Me.lb_reservation_info.Size = New System.Drawing.Size(125, 12)
        Me.lb_reservation_info.TabIndex = 9
        Me.lb_reservation_info.Text = "현재 예약이 없습니다."
        '
        'lbox_reservation_list
        '
        Me.lbox_reservation_list.FormattingEnabled = True
        Me.lbox_reservation_list.ItemHeight = 12
        Me.lbox_reservation_list.Location = New System.Drawing.Point(472, 49)
        Me.lbox_reservation_list.Name = "lbox_reservation_list"
        Me.lbox_reservation_list.Size = New System.Drawing.Size(169, 232)
        Me.lbox_reservation_list.TabIndex = 10
        '
        'btn_reservation_reseve
        '
        Me.btn_reservation_reseve.Location = New System.Drawing.Point(472, 307)
        Me.btn_reservation_reseve.Name = "btn_reservation_reseve"
        Me.btn_reservation_reseve.Size = New System.Drawing.Size(169, 49)
        Me.btn_reservation_reseve.TabIndex = 13
        Me.btn_reservation_reseve.Text = "예약삭제"
        Me.btn_reservation_reseve.UseVisualStyleBackColor = True
        '
        'gb_reservation_info
        '
        Me.gb_reservation_info.Controls.Add(Me.lb_useTime)
        Me.gb_reservation_info.Controls.Add(Me.lb_startTime)
        Me.gb_reservation_info.Controls.Add(Me.lb_room_number)
        Me.gb_reservation_info.Location = New System.Drawing.Point(663, 49)
        Me.gb_reservation_info.Name = "gb_reservation_info"
        Me.gb_reservation_info.Size = New System.Drawing.Size(200, 134)
        Me.gb_reservation_info.TabIndex = 14
        Me.gb_reservation_info.TabStop = False
        Me.gb_reservation_info.Text = "예약정보"
        '
        'lb_useTime
        '
        Me.lb_useTime.AutoSize = True
        Me.lb_useTime.Location = New System.Drawing.Point(7, 107)
        Me.lb_useTime.Name = "lb_useTime"
        Me.lb_useTime.Size = New System.Drawing.Size(57, 12)
        Me.lb_useTime.TabIndex = 1
        Me.lb_useTime.Text = "사용시간 "
        '
        'lb_startTime
        '
        Me.lb_startTime.AutoSize = True
        Me.lb_startTime.Location = New System.Drawing.Point(7, 69)
        Me.lb_startTime.Name = "lb_startTime"
        Me.lb_startTime.Size = New System.Drawing.Size(57, 12)
        Me.lb_startTime.TabIndex = 1
        Me.lb_startTime.Text = "시작시간 "
        '
        'lb_room_number
        '
        Me.lb_room_number.AutoSize = True
        Me.lb_room_number.Location = New System.Drawing.Point(7, 33)
        Me.lb_room_number.Name = "lb_room_number"
        Me.lb_room_number.Size = New System.Drawing.Size(69, 12)
        Me.lb_room_number.TabIndex = 0
        Me.lb_room_number.Text = "회의실번호 "
        '
        'gb_room_state
        '
        Me.gb_room_state.Controls.Add(Me.checkbox_room5)
        Me.gb_room_state.Controls.Add(Me.checkbox_room4)
        Me.gb_room_state.Controls.Add(Me.checkbox_room3)
        Me.gb_room_state.Controls.Add(Me.checkbox_room2)
        Me.gb_room_state.Controls.Add(Me.checkbox_room1)
        Me.gb_room_state.Location = New System.Drawing.Point(663, 224)
        Me.gb_room_state.Name = "gb_room_state"
        Me.gb_room_state.Size = New System.Drawing.Size(200, 132)
        Me.gb_room_state.TabIndex = 14
        Me.gb_room_state.TabStop = False
        Me.gb_room_state.Text = "회의실상태"
        '
        'checkbox_room5
        '
        Me.checkbox_room5.AutoSize = True
        Me.checkbox_room5.Location = New System.Drawing.Point(9, 100)
        Me.checkbox_room5.Name = "checkbox_room5"
        Me.checkbox_room5.Size = New System.Drawing.Size(78, 16)
        Me.checkbox_room5.TabIndex = 1
        Me.checkbox_room5.Text = "5번회의실"
        Me.checkbox_room5.UseVisualStyleBackColor = True
        '
        'checkbox_room4
        '
        Me.checkbox_room4.AutoSize = True
        Me.checkbox_room4.Location = New System.Drawing.Point(91, 60)
        Me.checkbox_room4.Name = "checkbox_room4"
        Me.checkbox_room4.Size = New System.Drawing.Size(78, 16)
        Me.checkbox_room4.TabIndex = 1
        Me.checkbox_room4.Text = "4번회의실"
        Me.checkbox_room4.UseVisualStyleBackColor = True
        '
        'checkbox_room3
        '
        Me.checkbox_room3.AutoSize = True
        Me.checkbox_room3.Location = New System.Drawing.Point(9, 60)
        Me.checkbox_room3.Name = "checkbox_room3"
        Me.checkbox_room3.Size = New System.Drawing.Size(78, 16)
        Me.checkbox_room3.TabIndex = 1
        Me.checkbox_room3.Text = "3번회의실"
        Me.checkbox_room3.UseVisualStyleBackColor = True
        '
        'checkbox_room2
        '
        Me.checkbox_room2.AutoSize = True
        Me.checkbox_room2.Location = New System.Drawing.Point(91, 20)
        Me.checkbox_room2.Name = "checkbox_room2"
        Me.checkbox_room2.Size = New System.Drawing.Size(78, 16)
        Me.checkbox_room2.TabIndex = 0
        Me.checkbox_room2.Text = "2번회의실"
        Me.checkbox_room2.UseVisualStyleBackColor = True
        '
        'checkbox_room1
        '
        Me.checkbox_room1.AutoSize = True
        Me.checkbox_room1.Location = New System.Drawing.Point(9, 20)
        Me.checkbox_room1.Name = "checkbox_room1"
        Me.checkbox_room1.Size = New System.Drawing.Size(78, 16)
        Me.checkbox_room1.TabIndex = 0
        Me.checkbox_room1.Text = "1번회의실"
        Me.checkbox_room1.UseVisualStyleBackColor = True
        '
        'btn_open
        '
        Me.btn_open.Location = New System.Drawing.Point(406, 12)
        Me.btn_open.Name = "btn_open"
        Me.btn_open.Size = New System.Drawing.Size(26, 344)
        Me.btn_open.TabIndex = 15
        Me.btn_open.Text = "<"
        Me.btn_open.TextAlign = System.Drawing.ContentAlignment.MiddleRight
        Me.btn_open.UseVisualStyleBackColor = True
        '
        'dlayTimer
        '
        Me.dlayTimer.Interval = 1000
        '
        'Form1
        '
        Me.AutoScaleDimensions = New System.Drawing.SizeF(7.0!, 12.0!)
        Me.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font
        Me.AutoSizeMode = System.Windows.Forms.AutoSizeMode.GrowAndShrink
        Me.ClientSize = New System.Drawing.Size(884, 371)
        Me.Controls.Add(Me.btn_open)
        Me.Controls.Add(Me.gb_room_state)
        Me.Controls.Add(Me.gb_reservation_info)
        Me.Controls.Add(Me.btn_reservation_reseve)
        Me.Controls.Add(Me.lbox_reservation_list)
        Me.Controls.Add(Me.lb_reservation_info)
        Me.Controls.Add(Me.btn_fold)
        Me.Controls.Add(Me.tb_reservation_info)
        Me.Controls.Add(Me.btn_reservation)
        Me.Controls.Add(Me.cb_useTime)
        Me.Controls.Add(Me.lb_info_2)
        Me.Controls.Add(Me.lb_info_1)
        Me.Controls.Add(Me.cb_minute)
        Me.Controls.Add(Me.cb_hour)
        Me.Controls.Add(Me.cb_room_select)
        Me.Controls.Add(Me.lb_second)
        Me.Controls.Add(Me.lb_minute)
        Me.Controls.Add(Me.lb_hour)
        Me.Controls.Add(Me.lb_ampm)
        Me.Name = "Form1"
        Me.Text = "회의실예약시스템"
        Me.gb_reservation_info.ResumeLayout(False)
        Me.gb_reservation_info.PerformLayout()
        Me.gb_room_state.ResumeLayout(False)
        Me.gb_room_state.PerformLayout()
        Me.ResumeLayout(False)
        Me.PerformLayout()

    End Sub

    Friend WithEvents lb_ampm As Label
    Friend WithEvents lb_hour As Label
    Friend WithEvents lb_minute As Label
    Friend WithEvents lb_second As Label
    Friend WithEvents cb_room_select As ComboBox
    Friend WithEvents cb_hour As ComboBox
    Friend WithEvents lb_info_1 As Label
    Friend WithEvents cb_minute As ComboBox
    Friend WithEvents lb_info_2 As Label
    Friend WithEvents cb_useTime As ComboBox
    Friend WithEvents btn_reservation As Button
    Friend WithEvents tb_reservation_info As TextBox
    Friend WithEvents btn_fold As Button
    Friend WithEvents lb_reservation_info As Label
    Friend WithEvents lbox_reservation_list As ListBox
    Friend WithEvents btn_reservation_reseve As Button
    Friend WithEvents gb_reservation_info As GroupBox
    Friend WithEvents lb_useTime As Label
    Friend WithEvents lb_startTime As Label
    Friend WithEvents lb_room_number As Label
    Friend WithEvents gb_room_state As GroupBox
    Friend WithEvents checkbox_room5 As CheckBox
    Friend WithEvents checkbox_room4 As CheckBox
    Friend WithEvents checkbox_room3 As CheckBox
    Friend WithEvents checkbox_room2 As CheckBox
    Friend WithEvents checkbox_room1 As CheckBox
    Friend WithEvents btn_open As Button
    Friend WithEvents dlayTimer As Timer
End Class
