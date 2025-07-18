package com.coffee_is_essential.iot_cloud_ota.controller;

import com.coffee_is_essential.iot_cloud_ota.dto.DivisionSummaryResponseDto;
import com.coffee_is_essential.iot_cloud_ota.service.DivisionService;
import lombok.RequiredArgsConstructor;
import org.springframework.http.HttpStatus;
import org.springframework.http.ResponseEntity;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

import java.util.List;

/**
 * 펌웨어 그룹 관련 요청을 처리하는 REST 컨트롤러 입니다.
 */
@RestController
@RequestMapping("/api/divisions")
@RequiredArgsConstructor
public class DivisionController {
    private final DivisionService divisionService;

    /**
     * 전체 그룹의 요약 정보를 조회합니다.
     * 각 그룹에는 몇 개의 디바이스가 등록되어 있는지를 포함한 정보가 반환됩니다.
     *
     * @return 그룹 ID, 그룹 코드, 그룹 이름, 등록된 디바이스 수를 포함한 리스트와 HTTP 200 OK 응답
     */
    @GetMapping
    public ResponseEntity<List<DivisionSummaryResponseDto>> findDivisionSummary() {
        List<DivisionSummaryResponseDto> list = divisionService.findDivisionSummary();

        return new ResponseEntity<>(list, HttpStatus.OK);
    }
}
